package OpenHelper;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import androidx.annotation.Nullable;
import java.util.ArrayList;

import Entidad.Mascota;

public class OpenHelper extends SQLiteOpenHelper {

    public static String MascotasCreaciontable="CREATE TABLE IF NOT EXISTS mascotas(_ID integer primary key autoincrement, Nombre text, anio integer);";
    public static String MascotasTable="mascotas";
    public static String MascotasColumnaID="_ID";
    public static String MascotasColumnaNombre="Nombre";
    public static String MascotasColumnaAnio="anio";
    public OpenHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        // Crea las tablas
        String query= MascotasCreaciontable;
        db.execSQL(query);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }

    public void abrir()
    {
        this.getWritableDatabase();
    }

    public void cerrar()
    {
         this.close();
    }

    //Método que me permite insertar registros en la tabla usuarios

    public void insertarMascota(Mascota m)
    {
        ContentValues valores = new ContentValues();
        valores.put(MascotasColumnaNombre,m.getNombre());
        valores.put(MascotasColumnaAnio,m.getEdad());
        this.getWritableDatabase().insert(MascotasTable,null,valores);
    }


    public void eliminarMascota(Mascota m)
    {
        String id = String.valueOf(m.getId());
        this.getWritableDatabase().delete(MascotasTable,"_ID=?",new String[]{id});
    }

    public ArrayList<Mascota> getListadoMascotas()
    {
        ArrayList<Mascota> listaMascota = new ArrayList<Mascota>();
        Cursor mcursor = null;
        mcursor = this.getReadableDatabase().query(MascotasTable,
                new String[]{MascotasColumnaID,MascotasColumnaNombre,MascotasColumnaAnio},
                null,null,null,null,null);

        if(mcursor.moveToFirst())
        {
            do{
                Mascota m = new Mascota();
                m.setId(mcursor.getInt(0));
                m.setNombre(mcursor.getString(1));
                m.setEdad(mcursor.getInt(2));
                listaMascota.add(m);
            }
            while(mcursor.moveToNext());
        }
        return listaMascota;
    }

}
