<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="MenuMedico.aspx.cs" Inherits="Vista.Medico.MenuMedico" %>
<asp:Content ID="Contenido1" ContentPlaceHolderID="head" runat="server">
<link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'><%-- CSS SÓLO para esta página --%>
<style>    
  .titulo{ /*B*/
    color: #333;
    border-bottom: 2px solid #007bff;
    padding-bottom: 10px;
    margin-bottom: 25px;
    font-size: 28px;
    text-align: center;
  }
        
  .panel { /*B FLEX*/
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    gap: 25px;
    padding: 20px 0;
  }


  .tarjeta { /*B*/
    background-color: #ffffff;
    border-radius: 10px;
    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
    padding: 25px;
    text-align: center;
    transition: transform 0.3s, box-shadow 0.3s, border-color 0.3s;
    text-decoration: none;
    color: #333;
    border: 1px solid #eee;
    flex-basis: 280px;
    flex-grow: 1;
    max-width: 380px;
  }

  .tarjeta__icono { /*E*/
    font-size: 50px; 
    color: #007bff; 
    margin-bottom: 20px;
    display: block;
  }

  .tarjeta__titulo { /*E*/
    font-size: 22px;
    margin-bottom: 15px;
    color: #007bff;
    transition: text-shadow 0.3s;
  }

  .tarjeta__parrafo { /*E*/
    font-size: 16px;
    color: #555;
    line-height: 1.5;
  }

  .tarjeta:hover { 
    transform: translateY(-5px);
    box-shadow: 0 0 20px 5px rgba(0,123,255,0.4);
    border-color: #007bff;
  }

  .tarjeta:hover .tarjeta__titulo { 
    text-shadow: 0 0 10px rgba(0,123,255,0.6);
  }


  /*MODIFICADORES PARA TARJETA ESPECIAL*/
  .tarjeta--importante .tarjeta__icono,
  .tarjeta--importante .tarjeta__titulo {
    color: #dc3545; 
  }
        
  .tarjeta--importante:hover {
    border-color: #dc3545;
    box-shadow: 0 0 20px 5px rgba(220, 53, 69, 0.4); 
  }
        
  .tarjeta--importante:hover .tarjeta__titulo {
    text-shadow: 0 0 10px rgba(220, 53, 69, 0.6);
  }

</style>
</asp:Content>


<asp:Content ID="Contenido2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
  <h2 class="titulo">Panel de Administración</h2>
  <div class="panel">
    <a href="AdministrarTurnos/ListadoTurnos.aspx" class="tarjeta">
      <i class='bx bxs-calendar tarjeta__icono'></i>
      <h3 class="tarjeta__titulo">Gestionar Turnos</h3>
      <p class="tarjeta__parrafo">Gestionar Mis Turnos, asistencias y observaciones.</p>
    </a>
  </div>
</asp:Content>
