package frgp.utn.edu.ar.appmobile_controles;

import android.os.Bundle;
import android.util.Patterns;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private Switch switchSiNO;
    private EditText etNombre;
    private EditText etCorreo;
    private EditText etFechaNac;
    private CheckBox chkDeporte;
    private CheckBox chkMusica;
    private CheckBox chkVideojuegos;
    private RadioGroup radioGroup;

    private TextView txtViewResultado;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

         switchSiNO = findViewById(R.id.switchSiNo);
         switchSiNO.setOnCheckedChangeListener((buttonView, isChecked) -> {
             if(isChecked)
             {
                 switchSiNO.setText("Si");
             }
             else
             {
                 switchSiNO.setText("No");
             }
         });

         etNombre = findViewById(R.id.etNombre);
         etCorreo = findViewById(R.id.etCorreo);
         etFechaNac = findViewById(R.id.etFechaNacimiento);

         chkDeporte = findViewById(R.id.chkDeporte);
         chkMusica = findViewById(R.id.chkMusica);
         chkVideojuegos = findViewById(R.id.chkVideojuegos);

         radioGroup = findViewById(R.id.rgGenero);

        txtViewResultado = findViewById(R.id.tvResultado);
    }

    public boolean validaciones()
    {
        boolean estado = true;

        etNombre.setError(null);
        etCorreo.setError(null);
        etFechaNac.setError(null);

        if(etNombre.getText().toString().isEmpty())
        {
            etNombre.setError("Campo requerido");
            estado = false;
        }
        else
        {
            if(etNombre.getText().toString().length() < 3)
            {
                etNombre.setError("Mínimo 3 caracteres");
                estado = false;
            }
        }

        if(etCorreo.getText().toString().isEmpty())
        {
            etCorreo.setError("Campo requerido");
            estado = false;
        }
        else {
            if(!Patterns.EMAIL_ADDRESS.matcher(etCorreo.getText().toString()).matches())
            {
                estado = false;
                etCorreo.setError("Correo inválido");
            }
        }

        if(etFechaNac.getText().toString().isEmpty())
        {
            etFechaNac.setError("Campo requerido");
            estado = false;
        }

        if(chkDeporte.isChecked() == false && chkMusica.isChecked() == false && chkVideojuegos.isChecked() == false)
        {
            Toast.makeText(this, "Debe seleccionar al menos un interes", Toast.LENGTH_SHORT).show();
            estado = false;
        }

        int idSeleccionado = radioGroup.getCheckedRadioButtonId();
        if(idSeleccionado == -1)
        {
            Toast.makeText(this, "Debe seleccionar un genero", Toast.LENGTH_SHORT).show();
            estado = false;
        }

        return estado;
    }

    public void eventoBoton(View view) {

        if(validaciones() == false) {
            return;
        }

        String nombre = etNombre.getText().toString();
        String correo = etCorreo.getText().toString();
        String fechaNac = etFechaNac.getText().toString();
        String elementosCheckeados = "";

        elementosCheckeados += "Resultado: "+ "\n";
        elementosCheckeados += "Nombre: " + nombre + "\n";
        elementosCheckeados += "Correo: " + correo + "\n";
        elementosCheckeados += "Fecha Nacimiento: " + fechaNac + "\n";

        elementosCheckeados += "Intereses: " + "\n";
        if(chkDeporte.isChecked())
        {
            elementosCheckeados += chkDeporte.getText().toString() + "\n";
        }
        if(chkMusica.isChecked())
        {
            elementosCheckeados += chkMusica.getText().toString() + "\n";
        }
        if(chkVideojuegos.isChecked())
        {
            elementosCheckeados += chkVideojuegos.getText().toString() + "\n";
        }

        elementosCheckeados += "Genero: " + "\n";

        int idSeleccionado = radioGroup.getCheckedRadioButtonId();
        if(idSeleccionado != -1)
        {
            RadioButton RB = findViewById(idSeleccionado);
            elementosCheckeados += RB.getText().toString() + "\n";
        }

        elementosCheckeados += "Desea recibir información?: " + "\n";

        if(switchSiNO.isChecked())
        {
            elementosCheckeados += "Si" + "\n";
        }
        else
        {
            elementosCheckeados += "No" + "\n";
        }

        txtViewResultado.setText(elementosCheckeados);
    }
}