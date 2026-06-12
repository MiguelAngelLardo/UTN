package frgp.utn.edu.ar.appmobile_sqlite;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import android.content.Intent;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import Entidad.Mascota;
import OpenHelper.OpenHelper;


public class AgregarAnimalesMainActivity extends AppCompatActivity {

    private EditText editTextNombre;
    private EditText editTextEdad;
    private Button btnAgregar;
    private Mascota m;
    private OpenHelper bd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_agregar_animales_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        editTextNombre = (EditText) findViewById(R.id.editTextNombre);
        editTextEdad = (EditText) findViewById(R.id.editTextEdad);
        btnAgregar = (Button) findViewById(R.id.btnAgregar);
        bd = new OpenHelper(this, "BD_Mascotas", null, 1);
        btnAgregar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                m = new Mascota();
                m.setNombre(editTextNombre.getText().toString());
                m.setEdad(Integer.parseInt(editTextEdad.getText().toString()));
                bd.insertarMascota(m);
                editTextNombre.setText("");
                editTextEdad.setText("");
                Toast toast2 = Toast.makeText(getApplicationContext(), "Registro agregado con éxito", Toast.LENGTH_SHORT);
                toast2.setGravity(Gravity.CENTER | Gravity.LEFT, 0, 0);
                toast2.show();
            }

        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.opcion1) {
            Intent intent = new Intent(this, AgregarAnimalesMainActivity.class);
            startActivity(intent);
            return true;
        }

        if (id == R.id.opcion2) {
            Intent intent = new Intent(this, ListadoAnimalesActivity.class);
            startActivity(intent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
