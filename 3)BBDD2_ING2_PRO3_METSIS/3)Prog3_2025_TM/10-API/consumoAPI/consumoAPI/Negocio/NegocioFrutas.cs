using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Datos;
using Entidades;

namespace Negocio
{
    public class NegocioFrutas
    {
        private ApiFruta apiFruta;
        public async Task<List<FrutasPlanas>> ObtenerTodas()
        {
            apiFruta = new ApiFruta();
            List<Fruta> frutas = await apiFruta.ObtenerTodas();
            return ObtenerFrutasPlanas(frutas);
        }

        public async Task<List<FrutasPlanas>> ObtenerPorFamilia(string familia)
        {
            apiFruta = new ApiFruta();
            List<Fruta> frutas = await apiFruta.ObtenerPorFamilia(familia);
            return ObtenerFrutasPlanas(frutas);
        }

        public async Task<List<FrutasPlanas>> ObtenerPorNutricion(string tipoNutricion,
                                                                  double min, double max) {
            apiFruta = new ApiFruta();
            List<Fruta> frutas = await apiFruta.ObtenerPorNutricion(tipoNutricion, min, max);
            return ObtenerFrutasPlanas(frutas);
        }

        public List<FrutasPlanas> ObtenerFrutasPlanas(List<Fruta> frutas)
        {
            List<FrutasPlanas> frutasPlanas = new List<FrutasPlanas>();

            foreach (var f in frutas)
            {
                frutasPlanas.Add(new FrutasPlanas
                {
                    id = f.id,
                    name = f.name,
                    family = f.family,
                    genus = f.genus,
                    order = f.order,
                    carbohydrates = f.nutritions?.carbohydrates ?? 0,
                    protein = f.nutritions?.protein ?? 0,
                    fat = f.nutritions?.fat ?? 0,
                    calories = f.nutritions?.calories ?? 0,
                    sugar = f.nutritions?.sugar ?? 0
                });
            }

            return frutasPlanas;

        }

    }
}
