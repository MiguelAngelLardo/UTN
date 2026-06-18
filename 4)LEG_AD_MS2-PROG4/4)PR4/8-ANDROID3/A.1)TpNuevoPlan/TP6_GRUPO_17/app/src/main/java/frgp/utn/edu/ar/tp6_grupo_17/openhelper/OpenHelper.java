package frgp.utn.edu.ar.tp6_grupo_17.openhelper;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import androidx.annotation.Nullable;

import android.content.ContentValues;//para insertar


import frgp.utn.edu.ar.tp6_grupo_17.entidad.Contacto; //para clase contacto

import java.util.ArrayList;//para listar
import android.database.Cursor;//para listar


public class OpenHelper  extends SQLiteOpenHelper {
  //Dato Globales
  public static final String NOMBRE_BD = "BDContactos"; //para pantalla dos
  public static final int VERSION = 1;//para pantalla 2 o onUpgrade
  public static final String TABLA = "CONTACTOS";

  //Datos especificos
  public static final String COL_ID = "IdContacto_CON";
  public static final String COL_NOMBRE = "Nombre_CON";
  public static final String COL_APELLIDO = "Apellido_CON";
  public static final String COL_TELEFONO = "Telefono_CON";
  public static final String COL_TIPO_TELEFONO = "TipoTelefono_CON";
  public static final String COL_EMAIL = "Email_CON";
  public static final String COL_TIPO_EMAIL = "TipoEmail_CON";
  public static final String COL_DIRECCION = "Direccion_CON";
  public static final String COL_FECHA_NAC = "FechaNacimiento_CON";
  public static final String COL_NIVEL_ESTUDIO = "NivelEstudio_CON";
  public static final String COL_INTERESES = "Intereses_CON";
  public static final String COL_RECIBIR_INFO = "RecibirInfo_CON";//no usa bit o boolean sqlLite

  //Creacion
  public static final String CREAR_TABLA =
      "CREATE TABLE IF NOT EXISTS " + TABLA + " (" +
          COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
          COL_NOMBRE + " TEXT, " +
          COL_APELLIDO + " TEXT, " +
          COL_TELEFONO + " TEXT, " +
          COL_TIPO_TELEFONO + " TEXT, " +
          COL_EMAIL + " TEXT, " +
          COL_TIPO_EMAIL + " TEXT, " +
          COL_DIRECCION + " TEXT, " +
          COL_FECHA_NAC + " TEXT, " +
          COL_NIVEL_ESTUDIO + " TEXT, " +
          COL_INTERESES + " TEXT, " +
          COL_RECIBIR_INFO + " INTEGER)";


  // Constructor (lo pide SQLiteOpenHelper)
  public OpenHelper(@Nullable Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
    super(context, name, factory, version);
  }

  @Override
  public void onCreate(SQLiteDatabase db) {  // se ejecuta una vez =>  crea la tabla
    String query = CREAR_TABLA;
    db.execSQL(query);
  }
  @Override//se ejecuta si subo el número de VERSION (ej: 1 a 2) para migrar la BD. => Como solo agrego y muestro, lo dejo vacío.
  public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) { }

  public void insertarContacto(Contacto contacto) {
    ContentValues registro= new ContentValues();
    registro.put(COL_NOMBRE, contacto.getNombre());
    registro.put(COL_APELLIDO, contacto.getApellido());
    registro.put(COL_TELEFONO, contacto.getTelefono());
    registro.put(COL_TIPO_TELEFONO, contacto.getTipoTelefono());
    registro.put(COL_EMAIL, contacto.getEmail());
    registro.put(COL_TIPO_EMAIL, contacto.getTipoEmail());
    registro.put(COL_DIRECCION, contacto.getDireccion());
    registro.put(COL_FECHA_NAC, contacto.getFechaNacimiento());
    registro.put(COL_NIVEL_ESTUDIO, contacto.getNivelEstudio());
    registro.put(COL_INTERESES, contacto.getIntereses());
    registro.put(COL_RECIBIR_INFO, contacto.getRecibirInfo() ? 1 : 0);//boolean que usa java lo paso a integer de sqllite
    getWritableDatabase().insert(TABLA, null, registro);
  }

  //Listar
  public ArrayList<Contacto> listarContactos() {
    ArrayList<Contacto> arrayListContactos = new ArrayList<>();
    Cursor cursor = getReadableDatabase().query(TABLA, null, null, null, null, null, null);
    if (cursor.moveToFirst()) {
      do {
        Contacto c = new Contacto();
        c.setIdContacto(cursor.getInt(0));
        c.setNombre(cursor.getString(1));
        c.setApellido(cursor.getString(2));
        c.setTelefono(cursor.getString(3));
        c.setTipoTelefono(cursor.getString(4));
        c.setEmail(cursor.getString(5));
        c.setTipoEmail(cursor.getString(6));
        c.setDireccion(cursor.getString(7));
        c.setFechaNacimiento(cursor.getString(8));
        c.setNivelEstudio(cursor.getString(9));
        c.setIntereses(cursor.getString(10));
        c.setRecibirInfo(cursor.getInt(11) == 1);
        arrayListContactos.add(c);
      } while (cursor.moveToNext());
    }
    cursor.close();
    return arrayListContactos;
  }

}

