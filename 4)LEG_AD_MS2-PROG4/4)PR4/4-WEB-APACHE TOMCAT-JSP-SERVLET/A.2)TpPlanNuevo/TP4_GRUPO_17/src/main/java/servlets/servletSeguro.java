package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//paralistar
import java.util.ArrayList;

//para devolver el ultimo ID al formulario en agregarSeguro y devovler el DDL
//import javax.servlet.RequestDispatcher; => se usa si RequestDispatcher rd = request.getRequestDispatcher("/AgregarSeguro.jsp"); pero como lo hago 1 unalina no hace falta

import dominio.*;
import dao.*;

//aca hay codigo java q se ejecuta en el servidor
@WebServlet("/servletSeguro") // si lepongo "pepito" lo localizo como "pepito" desde afuera
public class servletSeguro extends HttpServlet {
  private static final long serialVersionUID = 1L;
  public servletSeguro() {super();}

  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    SeguroDao seguroDao = new SeguroDao();

    if (request.getParameter("irAAgregar") != null) {

      // PARA PRIMIXO ID//
      int proximoId = seguroDao.obtenerUltimoId() + 1;

      // PARA DDL//
      TipoSegurosDao tipoSeguroDao = new TipoSegurosDao();
      ArrayList<TipoSeguro> listaTipos = tipoSeguroDao.listarTiposSeguros();

      request.setAttribute("listaTipos", listaTipos);
      request.setAttribute("proxId", proximoId);

      request.getRequestDispatcher("/AgregarSeguro.jsp").forward(request, response);

      /*
       * RequestDispatcher rd = request.getRequestDispatcher("/AgregarSeguro.jsp");
       * rd.forward(request, response);
       */
    }
    
    //guardar 
    if (request.getParameter("btnAceptar") != null) {
      // Borrar mensajes previos 
      request.removeAttribute("seAgrego");
      request.removeAttribute("msjError");

      try {
        // CAPTURA INICIAL de datos en STR
        String strCostoC = request.getParameter("txtCostoContratacion");
        String strCostoMax = request.getParameter("txtCostoMaximo");
        String descripcion = request.getParameter("txtDescripcion");
        String strIdTipo = request.getParameter("ddlTipoSeguro");

        // validar vacios
        if (strCostoC.isEmpty() || strCostoMax.isEmpty() || descripcion.isEmpty()) {
          request.setAttribute("msjError", "Todos los campos son obligatorios.");
        } else {
          // parsear los STR al tipo correspondiente
          double costoContratacion = Double.parseDouble(strCostoC);
          double costoMaximo = Double.parseDouble(strCostoMax);
          int idTipo = Integer.parseInt(strIdTipo);

          // Validar Negativos
          boolean costoCOK = (costoContratacion > 0);
          boolean costoMOK = (costoMaximo > 0);

          if (!costoCOK || !costoMOK) {//ternario para personalizar costo contratacion o costo maximo
            String msj = (!costoCOK && !costoMOK) ? "Ambos costos deben ser positivos." : (!costoCOK) ? "El costo de contratación debe ser positivo." : "El costo máximo asegurado debe ser positivo.";
            request.setAttribute("msjError", msj);
          } else {
            // Guardar
            Seguro seguro = new Seguro();
            seguro.setDescripcion(descripcion);
            seguro.setCostoContratacion(costoContratacion);
            seguro.setCostoAsegurado(costoMaximo);

            TipoSeguro ts = new TipoSeguro();//comp
            ts.setIdTipo(idTipo);//comp
            seguro.setTipoSeguro(ts);//comp

            int filas = seguroDao.agregarSeguro(seguro);
            if (filas > 0) {
              request.setAttribute("seAgrego", true);
            }
          }
        } // Else para vacios
      } catch (NumberFormatException e) {
        request.setAttribute("msjError", "Los campos de costo deben ser valores numéricos.");
      } catch (Exception e) {
        request.setAttribute("msjError", "Ocurrió un error inesperado: " + e.getMessage());
      }

      // recarga
      request.setAttribute("proxId", seguroDao.obtenerUltimoId() + 1);
      request.setAttribute("listaTipos", new TipoSegurosDao().listarTiposSeguros());

      request.getRequestDispatcher("/AgregarSeguro.jsp").forward(request, response);
    }

    // Cargar Pagina Listar + carga DDL con "-- Todos --
    if (request.getParameter("irAListar") != null) {
      TipoSegurosDao tipoDao = new TipoSegurosDao();

      ArrayList<Seguro> listaSeguros = seguroDao.listarSeguros();
      ArrayList<TipoSeguro> listaTipos = tipoDao.listarTiposSeguros();

      // Cargamos el request
      request.setAttribute("listaSeguros", listaSeguros);
      request.setAttribute("listaTipos", listaTipos);

      request.getRequestDispatcher("/ListarSeguros.jsp").forward(request, response);

    }

    /*
     * 
     * if(request.getParameter("btnFiltrar") != null) {//si apreta btn String
     * idSeleccionado = request.getParameter("ddlTipoSeguro"); //veo que tiene en
     * ddl
     * 
     * // Si elige "-- Todos --" uso el valor 0 con el listar todo ArrayList<Seguro>
     * listaFinal = idSeleccionado.equals("0") ? seguroDao.listarSeguros() :
     * seguroDao.listarPorIdTipo(idSeleccionado);
     * request.setAttribute("listaSeguros", listaFinal);
     * 
     * TipoSegurosDao tipoDao = new TipoSegurosDao();//para que el ddl se cargue de
     * vuelta request.setAttribute("listaTipos", tipoDao.listarTiposSeguros());
     * 
     * request.getRequestDispatcher("/ListarSeguros.jsp").forward(request,
     * response); }
     */

    // Capturamos AMBOS botones
    if (request.getParameter("btnFiltrar") != null || request.getParameter("btnMostrarTodos") != null) {

      String idSeleccionado = request.getParameter("ddlTipoSeguro");
      if (request.getParameter("btnMostrarTodos") != null)
        idSeleccionado = "0";// si apreto "mostrar todos" lo tomo como que ID esta en cero y mato 2 pajaros
                             // de un tiro, ah

      ArrayList<Seguro> listaFinal = idSeleccionado.equals("0") ? seguroDao.listarSeguros()
          : seguroDao.listarPorIdTipo(idSeleccionado);
      request.setAttribute("listaSeguros", listaFinal);
      TipoSegurosDao tipoDao = new TipoSegurosDao();
      request.setAttribute("listaTipos", tipoDao.listarTiposSeguros());
      request.getRequestDispatcher("/ListarSeguros.jsp").forward(request, response);
    }

  }

  protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    // traigo con post pero ejecuto por get
    doGet(request, response);
  }
}
