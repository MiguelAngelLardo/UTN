package frgp.utn.edu.ar.appmobile_sqlite;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import android.view.Gravity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import Entidad.Mascota;
import OpenHelper.OpenHelper;


public class ListadoAnimalesActivity extends AppCompatActivity {

    private OpenHelper bd;
    ListView lvMascotas;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_listado_animales);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        bd= new OpenHelper(this,"BD_Mascotas",null,1);
        cargarListview();
        lvMascotas.setClickable(true);
        lvMascotas.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            @Override
            public void onItemClick(AdapterView<?> arg0, View arg1, int position, long arg3) {

                Mascota m = new Mascota();
                m.setId(((Mascota)lvMascotas.getItemAtPosition(position)).getId());
                bd.eliminarMascota(m);

                Toast toast2 = Toast.makeText(getApplicationContext(),"Registro eliminado con éxito", Toast.LENGTH_SHORT);
                toast2.setGravity(Gravity.CENTER|Gravity.LEFT,0,0);
                toast2.show();
                cargarListview();

            }
        });
    }

    public void cargarListview()
    {
        ArrayList<Mascota> lMascotas= bd.getListadoMascotas();
        lvMascotas = (ListView) findViewById(R.id.lvMascotas);
        ArrayAdapter<Mascota> adapter = new ArrayAdapter<Mascota>(this, android.R.layout.simple_list_item_1, lMascotas);
        lvMascotas.setAdapter(adapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }

    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle item selection
        int id = item.getItemId();

        if (id == R.id.opcion1) {
            Intent intent = new Intent(this, AgregarAnimalesMainActivity.class);
            startActivity(intent);
            return true;
        }
        else if (id == R.id.opcion2) {
            Intent intent = new Intent(this, ListadoAnimalesActivity.class);
            startActivity(intent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}