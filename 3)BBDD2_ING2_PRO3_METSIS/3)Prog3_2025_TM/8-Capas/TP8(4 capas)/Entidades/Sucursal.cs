using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Sucursal
  {
    //Atributos para Listar
    private int _idSucursal;
    private string _nombreSucursal;
    private string _descripcionSucursal;
    private int _idProvincia;//para traerlo con relacion PK FK y muestre un string
    private string _direccionSucursal;

    //Constructor
    public Sucursal()
    {
      _idSucursal = -1;
      _nombreSucursal = "";
      _descripcionSucursal = "";
      _idProvincia = -1;
      _direccionSucursal = "";
    }

    //set
    public void setIdSucursal(int idSucursal){_idSucursal = idSucursal;}
    public void setNombreSucursal(string nombreSucursal){_nombreSucursal = nombreSucursal; }
    public void setDescripcionSucursal(string descripcionSucursal){_descripcionSucursal = descripcionSucursal; }
    public void setIdProvincia(int idProvincia){_idProvincia = idProvincia; }
    public void setDireccionSucursal(string direccionSucursal){_direccionSucursal = direccionSucursal; }

    //get
    public int getIdSucursal(){return _idSucursal; }
    public string getNombreSucursal(){return _nombreSucursal; }
    public string getDescripcionSucursal(){return _descripcionSucursal; }
    public int getIdProvincia(){return _idProvincia; }
    public string getDireccionSucursal(){return _direccionSucursal; }

  }
}
