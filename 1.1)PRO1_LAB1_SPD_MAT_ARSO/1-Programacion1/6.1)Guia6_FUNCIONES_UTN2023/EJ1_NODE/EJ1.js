/*1) Escribir un subprograma para que dados dos números enteros, obtengamos la suma
de ambos. */

//mnemo
//11 tote => stream/flujo (flujo de mujer) + objeto(caja) + 
         //in y out=>  proceso => pro-hacia adelante (ver zapatilla) + cedere (andar, marchar, ceder, retirar) => veo zapatos marchando 
//12 tina => pidiendo (require) una linea (droga) + lentes (leer)
//13 tomo => interfaz => tomo con antifaz



//Ejemplo 1 funcion clasica
function fSuma1(num1, num2){
  return num1 + num2;
}

console.log(fSuma1(0,1));

//ejemplo 2 funcion anonima
var varFunSuma2 = function fSuma2(n1, n2){
  return n1 + n2;
} 
console.log(varFunSuma2(0,2));

//ejemplo 3 fx flecha
var varFunSuma3a = (numero1, numero2) => {return numero1 + numero2}; // numero1 + numero2
console.log(varFunSuma3a(0,3.1));
var varFunSuma3b = (numero1, numero2) => numero1 + numero2;
console.log(varFunSuma3b(0,3.2));


//ejemplo 4 callback
function fCallSuma4(n1,n2, callPorParam){
  return callPorParam(n1,n2);
}

//clasica + call
console.log(fCallSuma4(0,4.1, fSuma1));

//anonima + call
console.log(fCallSuma4(0,4.2, varFunSuma2));

//flceha + call
console.log(fCallSuma4(0,4.3, varFunSuma3a));

//flecha inline + call 
console.log(fCallSuma4 (100, 100, (n1,n2) => n1 + n2));



//Ejemplo 5 - ingreso de datos
//funcion simple
function fIngresoSuma5(num1, num2){
  return num1 + num2;
}

//objeto en JS (no usa clase) => usamos el formato clave valor
//process es objeto global de node
const stream = {
  input: process.stdin,
  output: process.stdout
};

//readline es un objeto que nos permite leer por teclado
//createInterface es un método del módulo readline se utiliza para crear una nueva instancia de la interfaz de entrada/salida
//El método createInterface recibe un parámetro que es un objeto de configuración. 
//Este objeto contiene las propiedades que especifican las fuentes de entrada y salida para la interfaz.

const leerLinea = require ('readline');
const rl = leerLinea.createInterface(stream);

//question espera un parametro string y una funcion callback por parametro
rl.question('Ingrese un número: ', (n1) => {
  rl.question('Ingrese otro número: ', (n2) => {
    const resultado = fIngresoSuma5(parseInt(n1), parseInt(n2));
    console.log(`La suma es: ${resultado}`);
    rl.close(); // Cierra la interfaz de readline
  });
});




