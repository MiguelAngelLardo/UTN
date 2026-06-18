package frgp.utn.edu.ar.tp6_grupo_17;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import frgp.utn.edu.ar.tp6_grupo_17.entidad.Contacto;   // para Contacto
import android.view.View;//para la interfaz
import android.widget.Toast; //para el Toast

import android.widget.Button;     // por btnGuardar
import android.widget.RadioGroup; //para los grupos
import android.widget.RadioButton; //para el radio individual
import android.widget.CheckBox;   // por los chk
import android.widget.Switch; //para switch

import frgp.utn.edu.ar.tp6_grupo_17.openhelper.OpenHelper;  //para la bbdd
import android.content.Intent;//para irnos al .xml dellistar


public class AgregarContactosPlus extends AppCompatActivity {
  private Button btnGuardar;
  private CheckBox chkDeporte, chkMusica, chkArte, chkTecnologia;
  private RadioGroup rgNivelEstudios;
  private Switch switchRecibir;
  private Contacto objContacto;   //para recibir contacto semi cargado de pantalla 1
  private OpenHelper openHelperBD;//para sqllite

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    EdgeToEdge.enable(this);
    setContentView(R.layout.activity_agregar_contactos_plus);
    ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
      Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
      v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
      return insets;
    });

    //cargar controles
    btnGuardar = findViewById(R.id.btnGuardar);

    // recibír el contacto de pantalla 1
    objContacto = (Contacto) getIntent().getSerializableExtra("contacto");

    //carga de datos
    rgNivelEstudios = findViewById(R.id.radioGroupEstudios);
    chkDeporte = findViewById(R.id.chkDeporte);
    chkMusica = findViewById(R.id.chkMusica);
    chkArte = findViewById(R.id.chkArte);
    chkTecnologia = findViewById(R.id.chkTecnologia);
    switchRecibir = findViewById(R.id.switchRecibir);
    switchRecibir.setOnCheckedChangeListener((buttonView, isChecked) ->  switchRecibir.setText(isChecked ? "Sí" : "No"));//cambio el string con java en el .xml

    //instancia de obj de tipo bbdd
    openHelperBD = new OpenHelper(AgregarContactosPlus.this, OpenHelper.NOMBRE_BD, null, OpenHelper.VERSION);


    View.OnClickListener listenerGuardar = new View.OnClickListener() {
      @Override
      public void onClick(View v) {
        if (!validacionesPlus()) return;

        // Leo el radio seleccionado
        int idSeleccionado = rgNivelEstudios.getCheckedRadioButtonId();
        RadioButton rbElegido = findViewById(idSeleccionado);
        String nivelEstudio = rbElegido.getText().toString();

        // si esta todo OK concateno intereses
        String intereses = "";
        if (chkDeporte.isChecked())     intereses += "Deporte, ";
        if (chkMusica.isChecked())      intereses += "Música, ";
        if (chkArte.isChecked())        intereses += "Arte, ";
        if (chkTecnologia.isChecked())  intereses += "Tecnología, ";

        // Saco la coma y el espacio del final
        if (!intereses.isEmpty())   intereses = intereses.substring(0, intereses.length() - 2); //el 2 es para quita "," y elespacio

        //switch
        boolean recibirInfo = switchRecibir.isChecked();

        // Guardo los intereses, nivel de etudio y el switch
        objContacto.setIntereses(intereses);
        objContacto.setNivelEstudio(nivelEstudio);
        objContacto.setRecibirInfo(recibirInfo);

        //guardar en bbdd
        openHelperBD.insertarContacto(objContacto);
        Toast.makeText(AgregarContactosPlus.this, "Contacto " + objContacto.getNombre() + " " + objContacto.getApellido()+ " agregado con éxito", Toast.LENGTH_LONG).show();

        //vamos al listar
        Intent intent = new Intent(AgregarContactosPlus.this, ListadoContactos.class);
        startActivity(intent);

      }//onClick
    };//objetoAnonimo
    btnGuardar.setOnClickListener(listenerGuardar);
  }//onCreate

  public boolean validacionesPlus() {
    boolean estado = true;

    // al menos un nivel de estudios seleccionado
    int idSeleccionado = rgNivelEstudios.getCheckedRadioButtonId();
    if (idSeleccionado == -1) {
      Toast.makeText(this, "Debe seleccionar un nivel de estudios", Toast.LENGTH_LONG).show();
      estado = false;
    }

    // al menos un interés marcado
    if (!chkDeporte.isChecked() && !chkMusica.isChecked()  && !chkArte.isChecked() && !chkTecnologia.isChecked()) {
      Toast.makeText(this, "Debe seleccionar al menos un interés", Toast.LENGTH_LONG).show();
      estado = false;
    }

    return estado;
  }
}

