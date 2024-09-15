/*2) Escribir un subprograma para que dados dos números enteros, obtengamos el
máximo de ambos. */

//ejemplo1 funcion clasica
function fMax1(n1, n2){
  return (n1>n2) ? n1 : n2;
}
console.log(fMax1(4,3));

//ejemplo 2 funcion anonima
var varFunMax2 = function fMax2(n1,n2){
  return (n1>n2) ? n1 : n2;
}
console.log(varFunMax2(5,7));

//ejemplo 3 funcion flecha
var varFunMax3a = (n1,n2) => {return (n1>n2) ? n1 : n2;}
console.log(varFunMax3a(10,20));
var varFunMax3b = (n1,n2) =>  (n1>n2) ? n1 : n2;
console.log(varFunMax3b(10,20));

//ejemplo 4 call back
function fCallMax4 (n1,n2, callPorParam){
  return callPorParam(n1,n2);
}

//clasica + call
console.log(fCallMax4(2,4,fMax1));

//anonima + call
console.log(fCallMax4(6,8,varFunMax2));//tira error si uso fMax2 en el parametro ya que no es reconocido en el scope

//flecha + call
console.log(fCallMax4(10,8,varFunMax3a));

//flecha inline + call
console.log(fCallMax4(20,100, (n1,n2) => {return (n1 > n1) ? n1 : n2}));

//Ejemplo 5 - ingreso de datos
function fIngresoMax5(n1,n2){
  return (n1 > n2) ? n1 : n2;
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
const readline = require('readline');
const leerLinea = readline.createInterface(stream);

//question espera un parametro string y una funcion callback por parametro
leerLinea.question("Ingrese el primer numero: ", (num1) => {
  leerLinea.question("Ingrese el segundo numero: ", (num2) => {
    const resultado = fIngresoMax5(parseInt(num1), parseInt(num2));
    console.log(`El resultado es: ${resultado}`);
    leerLinea.close();
  });
});