package frgp.utn.edu.ar.tp6_grupo_17;

import android.os.Bundle;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;


import android.view.Menu;          // por onCreateOptionsMenu(Menu menu)
import android.view.MenuItem;      // por onOptionsItemSelected(MenuItem item)
import android.content.Intent;     // por new Intent(...)
import androidx.annotation.NonNull; // por @NonNull

import android.widget.Button; // por  Button btnContinuar
import android.view.View; // por  View.OnClickListener  y  View v

import android.widget.EditText;//para objetos de tipo EditText
import android.widget.Spinner;// para objetos de tipo Spinner

import frgp.utn.edu.ar.tp6_grupo_17.entidad.Contacto;

public class AgregarContactos extends AppCompatActivity { //AppCompatActivity deriba de Activity =>   posee el metodo findViewById

  //DECLARO varaibles de tipo control con  "declaración múltiple"
  private Button btnContinuar;
  private EditText etNombre, etApellido, etTelefono, etEmail, etDireccion, etFechaNac;
  private Spinner spTipoTelefono, spTipoEmail;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    EdgeToEdge.enable(this);
    setContentView(R.layout.activity_agregar_contactos);
    ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
      Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
      v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
      return insets;
    });

    //1-Cargo los Controles una vez.
    btnContinuar = findViewById(R.id.btnContinuar);
    etNombre = findViewById(R.id.editTextNombre);
    etApellido = findViewById(R.id.editTextApellido);

    etTelefono = findViewById(R.id.editTextTelefono);
    spTipoTelefono = findViewById(R.id.spinnerTelefono);

    etEmail = findViewById(R.id.editTextEmail);
    spTipoEmail = findViewById(R.id.spinnerEmail);

    etDireccion = findViewById(R.id.editTextDireccion);
    etFechaNac = findViewById(R.id.editTextFechaNacimiento);

    // 2-OnClickListener es una interfaz el QUE y necesita el COMO con el onClick => uso "anonymous classes" => new <Tipo>() { cuerpo }
    View.OnClickListener listenerContinuar = new View.OnClickListener() {
      @Override
      public void onClick(View v) {
        if (!validaciones())  return;   // Validacion igual que la profe

        // leer los valores
        String nombre = etNombre.getText().toString().trim();
        String apellido = etApellido.getText().toString().trim();
        String telefono = etTelefono.getText().toString().trim();
        String tipoTelefono = spTipoTelefono.getSelectedItem().toString();
        String email = etEmail.getText().toString().trim();
        String tipoEmail = spTipoEmail.getSelectedItem().toString();
        String direccion = etDireccion.getText().toString().trim();
        String fechaNac = etFechaNac.getText().toString().trim();

        //constructor sobre cargado con 8 parametros
        Contacto objContacto = new Contacto(nombre, apellido, telefono, tipoTelefono, email, tipoEmail, direccion, fechaNac);

        //me voy a otr pagina
        Intent intent = new Intent(AgregarContactos.this, AgregarContactosPlus.class);
        intent.putExtra("contacto", objContacto);
        startActivity(intent);//el Intent es la intención de ir a otra pantalla (Activity)".
      }
    };
    btnContinuar.setOnClickListener(listenerContinuar);
  }

  @Override //se ejecuta la primera vez cuando se crea la pantalla => dibuja el menu
  public boolean onCreateOptionsMenu(Menu menu) {
    //getInflador => convierte XML en algo visible en la pantalla
    //.inflate => R.menu.menu es res/menu -> menu.xml / menu es el menu vacio que toma del parametro del metodo
    getMenuInflater().inflate(R.menu.menu, menu);
    return true;
  }

  @Override//cuando toca una opcion se ejecuta el metodo
  public boolean onOptionsItemSelected(@NonNull MenuItem item) {//el parametro nunca sera Null
    int id = item.getItemId(); //obtengo el id de la opcion seleccionada

    // un Intent es una "intención de ir a otra pantalla". "desde esta pantalla (this), quiero ir a AgregarContactos".
    if (id == R.id.opcion_agregar) {
      Intent intent = new Intent(this, AgregarContactos.class);
      startActivity(intent);// ejecuta ese viaje, abre la otra pantalla.
      return true;
    } else if (id == R.id.opcion_listado) {
      Intent intent = new Intent(this, ListadoContactos.class);
      startActivity(intent);
      return true;
    }

    // si tocaron algo que no contemplamos le paso a la clase padre el comportamiento por defecto
    return super.onOptionsItemSelected(item);
  }

  public boolean validaciones() {
    boolean estado = true;   // arranca OK; si algo falla, pasa a false

    // Borramos el cartel "!" que haya quedado de antes => si escribe el valor OK el "!" se borra
    etNombre.setError(null);
    etApellido.setError(null);

    etTelefono.setError(null);
    //spTipoTelefono viene ya cargado

    etEmail.setError(null);
    //spTipoEmail viene ya cargado

    etDireccion.setError(null);
    etFechaNac.setError(null);

    // Leo los valores
    String nombre = etNombre.getText().toString().trim();
    String apellido = etApellido.getText().toString().trim();

    String telefono = etTelefono.getText().toString().trim();
    //spTipoTelefono viene ya cargado

    String email = etEmail.getText().toString().trim();
    //spTipoEmail viene ya cargado

    String direccion = etDireccion.getText().toString().trim();
    String fechaNac = etFechaNac.getText().toString().trim();

    //validaciones
    if (nombre.isEmpty()) {
      etNombre.setError("Campo requerido");
      estado = false;
    } else if (!nombre.matches("[A-Za-zÁ-ÿ\\s]+")) {
      etNombre.setError("Solo letras");
      estado = false;
    }

    if (apellido.isEmpty()) {
      etApellido.setError("Campo requerido");
      estado = false;
    } else if (!apellido.matches("[A-Za-zÁ-ÿ\\s]+")) {
      etApellido.setError("Solo letras");
      estado = false;
    }

    if (telefono.isEmpty()) {
      etTelefono.setError("Campo requerido");
      estado = false;
    } else if (!telefono.matches("[0-9-]+")) {
      etTelefono.setError("Solo números (con o sin guion)");
      estado = false;
    }

    if (email.isEmpty()) {
      etEmail.setError("Campo requerido");
      estado = false;
    } else if (!android.util.Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
      etEmail.setError("Correo inválido");
      estado = false;
    }

    if (direccion.isEmpty()) {
      etDireccion.setError("Campo requerido");
      estado = false;
    } else if (!direccion.matches("[A-Za-z0-9Á-ÿ\\s]+")) {
      etDireccion.setError("Sin símbolos especiales");
      estado = false;
    }

    if (fechaNac.isEmpty()) {
      etFechaNac.setError("Campo requerido");
      estado = false;
    } else if (!fechaNac.matches("\\d{2}/\\d{2}/\\d{4}")) {
      etFechaNac.setError("Formato dd/mm/aaaa");
      estado = false;
    }
    return estado;
  }
}
