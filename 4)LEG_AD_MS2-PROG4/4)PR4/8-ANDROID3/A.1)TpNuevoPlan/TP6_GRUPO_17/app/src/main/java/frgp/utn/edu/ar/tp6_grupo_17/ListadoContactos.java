package frgp.utn.edu.ar.tp6_grupo_17;

import android.os.Bundle;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import android.view.Menu;
import android.view.MenuItem;
import android.content.Intent;
import androidx.annotation.NonNull;

import android.widget.ListView; // para la "caja" de muestra del item uno debajo del otro => lvContactos
import frgp.utn.edu.ar.tp6_grupo_17.openhelper.OpenHelper;  //para la bbdd
import java.util.ArrayList; //para el array <Contacto>
import frgp.utn.edu.ar.tp6_grupo_17.entidad.Contacto;//para el array <Contacto>

import android.widget.ArrayAdapter;//el adapter toma el String y lo dibuja como fila

import android.widget.AdapterView; // por el OnItemClickListener
import android.view.View; //parametro del onItemClick
import androidx.appcompat.app.AlertDialog;  //  popup

public class ListadoContactos extends AppCompatActivity {

  private ListView lvContactos;
  private OpenHelper openHelperBD;
  private ArrayList<Contacto> listaContactos;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    EdgeToEdge.enable(this);
    setContentView(R.layout.activity_listado_contactos);
    setTitle("Contactos - TP6_GRUPO_17");
    ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
      Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
      v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
      return insets;
    });

    //cargo variables necesarias
    lvContactos = findViewById(R.id.listViewContactos); //cargo control completo
    openHelperBD = new OpenHelper(this, OpenHelper.NOMBRE_BD, null, OpenHelper.VERSION); //cargo nuestra bbdd
    listaContactos = openHelperBD.listarContactos();//cargo el array con el metodo listar


    // Armo la salida en pantalla con "nombre apellido - mail"
    ArrayList<String> lineas = new ArrayList<>();
    for (Contacto c : listaContactos) {
      lineas.add(c.getNombre() + " " + c.getApellido() + " – " + c.getEmail());
    }

    // Adapter simple (ya hecho por Android)
    ArrayAdapter<String> adaptadorBasico = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, lineas);
    lvContactos.setAdapter(adaptadorBasico);

    //muestro los detalles
    mostrarContactoCompleto();
  }

  @Override
  public boolean onCreateOptionsMenu(Menu menu) {
    getMenuInflater().inflate(R.menu.menu, menu);
    return true;
  }

  @Override
  public boolean onOptionsItemSelected(@NonNull MenuItem item) {
    int id = item.getItemId();

    if (id == R.id.opcion_agregar) {
      Intent intent = new Intent(this, AgregarContactos.class);
      startActivity(intent);
      return true;
    } else if (id == R.id.opcion_listado) {
      Intent intent = new Intent(this, ListadoContactos.class);
      startActivity(intent);
      return true;
    }

    return super.onOptionsItemSelected(item);
  }
  void mostrarContactoCompleto(){
    AdapterView.OnItemClickListener escuchaItemClick = new AdapterView.OnItemClickListener() {
      @Override//cuando hace clic en la fila llama a onItemClick y android llena los 4 parametros => pero el que mas se usa es position
      public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Contacto c = listaContactos.get(position);   // el contacto de la fila tocada
        String detalle =
            "Nombre: " + c.getNombre() + " " + c.getApellido() + "\n" +
                "Teléfono: " + c.getTelefono() + " (" + c.getTipoTelefono() + ")\n" +
                "Email: " + c.getEmail() + " (" + c.getTipoEmail() + ")\n" +
                "Dirección: " + c.getDireccion() + "\n" +
                "Fecha nac.: " + c.getFechaNacimiento() + "\n" +
                "Estudios: " + c.getNivelEstudio() + "\n" +
                "Intereses: " + c.getIntereses() + "\n" +
                "Recibir info: " + (c.getRecibirInfo() ? "Sí" : "No");

        new AlertDialog.Builder(ListadoContactos.this)
            .setTitle("Detalle del contacto")
            .setMessage(detalle)
            .setPositiveButton("Cerrar", null)
            .show();
      }
    };
    lvContactos.setOnItemClickListener(escuchaItemClick);
  }
}




