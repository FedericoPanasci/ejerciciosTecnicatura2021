//document.write("<p>" + num1 + " + " + num2 + " = " + resultado +"</p>");

//ejercicio 1

/*alert('hola');
var opcion = prompt('que cuenta quiere hacer?: ');
var num1 = parseInt(prompt('ingrese un numero: '));
var num2 = parseInt(prompt('ingrese otro numero: '));
var resultado;
if (opcion == "suma") {
    resultado = num1 + num2;
} 
else if (opcion == "resta") {
    resultado = num1 - num2;
} 
else if (opcion == "multiplicacion") {
    resultado = num1 * num2;
}
else{
    alert("ingreso una respuesta en la primer pregunta que no se puede resolver");
}

alert("Su resultado de " + opcion + " es: " + resultado);
*/

//ejercicio 2

/*
var resultado = 0;
var valor = 0;
alert('vamos a ingresar 10 notas')
for (let index = 0; index < 10; index++) {
    valor = parseInt(prompt('ingrese una nota: '))
    resultado += valor;
}

document.write('<p>El resultado del promedio de notas es: ' + (resultado / 10) + '</p>')
*/

//ejercicio velocidad

/*var distancia = 0;
const tiempo = 3;
var velocidad = 0;

distancia = parseInt(prompt("ingrese la distancia recorrida (en kilometros) en 3 segundos: "));
velocidad = distancia / tiempo;
alert('la velocidad es: ' + velocidad + ' km/h');*/

//ejercicio edades
/*var edades = [15, 17, 19, 21]
var suma = 0;
var promedio = 0;

for (var i = 0; i < edades.length; i++) {
    suma += edades[i];    
}
document.write('<p>La suma de las edades es:' + suma + '</p>');
promedio = suma / edades.length;
document.write('<p>El promedio de edades es: ' + promedio + '</p>'); */

//ejercicio azucares
/*var meses = 7;
var azucares = 15;
var resultado = 0;
for (let index = meses; index < 13; index++) {
    resultado = meses * azucares;
    document.write('<p>' + meses + " | " + resultado + '</p>');    
    meses++;
}*/

//ejercicio fecha
/*
----------------
getFullYear(); |
getMonth();    |
getDate();     |
getHours();    |
getMinutes();  |
getSeconds();  |
getDay();      |
----------------

var fecha = new Date();
var dia = fecha.getDay();

switch(dia){
    case 1: alert('que tengas buen lunes');
    break;
    case 2: alert('que tengas buen martes');
    break;
    case 3: alert('que tengas buen miercoles');
    break;
    case 4: alert('que tengas buen jueves');
    break;
    case 5: alert('que tengas buen viernes');
    break;
    case 6: alert('que tengas buen sabado');
    break;
    case 0: alert('que tengas buen domingo');
    break;
}*/
//DOM
/*
titulo = document.getElementById('titulo');
titulo.innerHTML = 'probando innerHTML';
titulo.style.color = "red";
titulo.style.background = "black";
titulo.style.margin = "auto";
*/

//integrador clase 2
/* var rol = prompt("cual es su rol?");
var contra = prompt("cual es la contraseña?");
if (rol == "admin" || rol == "recursos" && contra == "1234") {
    usuario = prompt('cual es su usuario?')
    var titulo = document.querySelector('h1');
    titulo.innerHTML = "bienvenido " + usuario + " a nuestra app"; 
} else {
    alert('Ha habido un error, pregunte a su supervisor rol y contraseña correctas')
} */

//arreglos
//array
/*var gente = new Array('fede', 'gabi', 'jere');
document.getElementById('titulo').innerHTML = gente;*/
//objeto
/*var objeto = new Object({nombre: 'fede', apellido: 'pepe'});
document.getElementById('titulo').innerHTML = (objeto.nombre +' '+ objeto.apellido);*/

//puedo acceder al ultimo elemento con ultimo = objeto[objeto.length - 1];

//ordenar con sort
/*
objeto.sort(function(a, b)){
    if (a.caracteristica > b.caracteristica){
        return 1;
    }
    if (a.caracteristica < b.caracteristica){
        return -1;
    }
    return 0;
}
*/
//insertar objeto con push al final
/*
var objeto = [{name: "juan"}, {name: "rodo"}];
objeto.push({name: "fede"}); //objeto.push('fede');
*/
//sacar elemento con pop al final
/*
var objeto = [{name: "juan"}, {name: "rodo"}];
objeto.pop();
*/
//insertar al principio con unshift
/*
var objeto = [{name: "juan"}, {name: "rodo"}];
objeto.unshift({name:"fede"});
*/
//eliminar del principio con shift
/* 
var objeto = [{name: "juan"}, {name: "rodo"}];
objeto.shift();
*/
//sacar con splice
//con splice se puede sacar un elemento de (x) una posicion dicha previamente, (y) se puede sacar a partir de esa posicion lo que se indique y se puede agregar (z)
/*
var objeto = [{name: "juan"}, {name: "rodo"}, {name: "toto"}];
objeto.splice(x 2, y 1, z {name: "fede"});
*/
//agrupar objetos con concat
/*
var objeto1 = [{name: "juan"}, {name: "rodo"}];
var objeto2 = [{name: "toto"}];
var objetos = objeto1.concat(objeto2);
*/
//romper un arreglo con slice
/*
var objeto = ["fede", "alberto", "tiano"];
var padres = objeto.slice(1);
document.getElementById('titulo').innerText = padres;
*/

//ejercicio de clase 3

// var datos = [];
// var cant = 0;
// var contenido = document.getElementById('tabla').innerHTML = '<tr><th>nombre</th><th>apellido</th><th>numero de camiseta</th></tr>';
// imprimir();

// function imprimir() {
//     for (var index = cant; index < datos.length; index++) {
//         contenido += '<tr><td>' + datos[index].nombre + '</td><td>' + datos[index].apellido + '</td><td>' + datos[index].numero + '</td></tr>'
//     }
//     cant = index;
//     document.getElementById('tabla').innerHTML = contenido;
// }

// function agregar() {
//     var nombre = document.getElementById('name').value;
//     var apellido = document.getElementById('ape').value;
//     var numero = document.getElementById('age').value;
//     datos.push({nombre:nombre, apellido:apellido, numero:numero})
//     imprimir();
//     limpiar();
// };

// function limpiar() {
//     document.getElementById('name').value = "";
//     document.getElementById('ape').value = "";
//     document.getElementById('age').value = "";
// };


//eventos
/*desde html:
<button "evento" ...
button + evento (onclick, onmouseover(pasa cursor por encima), onmouseout(aleja el cursor), onmousemove(mueve el cursor encima))
<input type="text" evento...
input text onchange (hace un cambio) onblur (deja de hacer foco) onfocus (hace foco) onkeypress (presionaste una tecla) onkeyup (deja de presionar una tecla)
desde javascript
document.querySelector('button').onclick = alerta()*/

//ejercicio de botones
//ejercicio 1
// var boton = document.getElementsByTagName('button');
// var titulo;
// for (let index = 0; index < boton.length; index++) {
//     boton[index].onclick = function () {
//         eleccion(this.innerHTML);
//     };
// }

// function eleccion(color) {
//     //alert('elgio el color ' + color);
//     titulo = document.getElementById('titulo').innerHTML = ('eligio el color ' + color);
//     document.write(titulo);
// }

/*var btn = document.getElementById('rojo');
btn.addEventListener("click", ()=>{
    console.log(btn.id);
})*/

//-------------------
// VALIDACIONES

// var input = document.getElementById('input');
// var btn = document.getElementById('buttom');

// btn.addEventListener('click', ()=>{
//     console.log(input.checkValidity())
// })

/*var form = document.getElementById('form');
var input = document.getElementById('input');

form.addEventListener("submit", (e)=>{
    e.defaultPrevented("click");
    let valor = input.value;
    let cant = valor.lenght
    if (cant > 3) {
        
    } else {
        input.setCustomValidity("no es menor a 3") //crea un mensaje personalizado en la pantalla (no consola)
    }
})*/

//trim() recorta espacios antes y despues de cualquier string
//includes() permite si dentro de un array hay un caracter un particular, en ("") va lo que se requiere validar
//encodeURIcomponent() transforma componentes

/*var form = document.querySelector('form');
var input = document.querySelector('input');

form.addEventListener("submit", (e)=>{
    e.preventDefault("click");
    let valor = input.value;
    let valor_trim = valor.trim(); //asi funciona trim
    let cant = valor_trim.length;
    console.log(valor_trim.includes(" ")); //asi funciona includes
    console.log(encodeURIcomponent(valor_trim));
    if (cant > 3) {
        
    } else {
        input.setCustomValidity("no es mayor a 3") //crea un mensaje personalizado en la pantalla (no consola)
    }
})*/

// EXPRESIONES REGULARES
//evita usar las funciones anteriores, se pone /validacion/, x ej: /ab/ busca que tenga ab en la palabra

//let regexp = /\w/; //valida alfabeticos y numericos
// \W con W mayuscula es lo contrario
// \d busca digitos y \D busca que no sean digitos
// \s busca espacios y saltos de linea, \S niega lo anterior
//si pongo una letra \a busca esa letra.
//para poner cantidad se usa {}, y se ponen dos numeros, minimo y maximo {N, M} o si se pone un numero indica que es un repetido, x ej= {l{2}}
//para buscar un grupo de caracteres se busca \(abc){2} x ejemplo encontraria abcabc
/*
con ^ = indica que el caracter esta al inicio del string (parrafo) ^a
$ = indica que esta al final del string a$
\b = boundry = al limite de una palabra \ba para al principio o a\b para el final
*/

//------------- validacion de formularios ----------
/*let form = document.querySelector("form");
let input = document.querySelector("input");

form.addEventListener("submit", (e) =>{
    e.preventDefault();
    let valor = input.value;
    let regexp = /^\w{5,10}$/;
    if(regexp.test(valor)){ //retorna bool
        console.log("valido");
    } else {
        console.log("invalido");
    }
})
*/
//--------------------------------------------------

// ----------- AJAX-----------------

//1) se crea la variable let xhr = new XMLHttpRequest; con xhr.readystate se puede saber el estado del xhr
//2) configurar con xhr.open("GET", "archivoDondeSeGuarda.txt"); se pueden usar: put - get - post - patch y delete
//3)xhr.send(); se envia los datos al archivo donde se guardan los datos

//XAMMP 
/*
Se inicia el panel y se start el apache
nos asigna un directorio y una ip, la pagina web de acceso es
localhost:
directorio restringido: c:xammp/htdocs (tiene que estar aca guardado). si el archivo se llama index inicia, sino hay q especificar nombre
xhr.status nos dice el estado del servidor.
xhr.response nos muestra que tiene adentro el xhr
*/