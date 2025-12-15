using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Sucursal
    {
        private int idSucursal;
        private String nombreSucursal;
        private String descripcionSucursal;
        private int idHorarioSucursal;
        private int idProvinciaSucursal;
        private String direccionSucursal;

        public Sucursal()
        {
            idSucursal = -1;
            nombreSucursal = "";
            descripcionSucursal = "";
            idHorarioSucursal = -1;
            idProvinciaSucursal = -1;
            direccionSucursal = "";
        }

        //  METODOS GET
        public int getIdSucursal(){return idSucursal;}
        public String getNombreSucursal(){return nombreSucursal;}
        public String getDescripcionSucursal(){return descripcionSucursal;}
        public int getIdHorarioSucursal(){return idHorarioSucursal;}
        public int getIdProvinciaSucursal(){return idProvinciaSucursal;}
        public String getDireccionSucursal(){return direccionSucursal;}

        //METODOS SET

        public void setIdSucursal(int idSucursal){this.idSucursal = idSucursal;}
        public void setNombreSucursal(String nombreSucursal){this.nombreSucursal = nombreSucursal;}
        public void setDescripcionSucursal(String descripcionSucursal){this.descripcionSucursal = descripcionSucursal;}
        public void setIdHorarioSucursal(int idHorarioSucursal){this.idHorarioSucursal = idHorarioSucursal;}
        public void setIdProvinciaSucursal(int idProvinciaSucursal){this.idProvinciaSucursal = idProvinciaSucursal;}
        public void setDireccionSucursal(String direccionSucursal){this.direccionSucursal = direccionSucursal;}
    }
}
