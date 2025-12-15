using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using Entidades;
using Newtonsoft.Json;////////incluir

namespace Datos
{
    public class ApiFruta
    {
        private readonly HttpClient _httpClient;

        public ApiFruta()
        {
            _httpClient = new HttpClient();
            _httpClient.BaseAddress = new Uri("https://www.fruityvice.com/");
            _httpClient.DefaultRequestHeaders.Accept.Clear();
            _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
        }

        public async Task<List<Fruta>> ObtenerTodas()
        {
            HttpResponseMessage response = await _httpClient.GetAsync("api/fruit/all");
            response.EnsureSuccessStatusCode();
            string jsonResult = await response.Content.ReadAsStringAsync();
            return JsonConvert.DeserializeObject<List<Fruta>>(jsonResult);
        }

        public async Task<List<Fruta>> ObtenerPorFamilia(string familia)
        {
            HttpResponseMessage response = await _httpClient.GetAsync("api/fruit/family/"+familia);
            response.EnsureSuccessStatusCode();

            string jsonResult = await response.Content.ReadAsStringAsync();
            return JsonConvert.DeserializeObject<List<Fruta>>(jsonResult);
        }

        public async Task<List<Fruta>> ObtenerPorNutricion(string tipoNutricion, double min = 0, double max = 1000)
        {

            HttpResponseMessage response = await _httpClient.GetAsync("/api/fruit/"+ tipoNutricion + "?min=" + min+ "&max=" +max);
            response.EnsureSuccessStatusCode();

            string jsonResult = await response.Content.ReadAsStringAsync();
            return JsonConvert.DeserializeObject<List<Fruta>>(jsonResult);
        }

        // Aquí pueden agregar métodos similares para genus, order, etc.
    }
}
