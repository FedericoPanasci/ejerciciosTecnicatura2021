function obtenerNombre(){
    return "fede";
}

function obtenerApellido(){
    return "javi";
}

function obtenerCompleto(){
    const nombre = obtenerNombre();
    const apellido = obtenerApellido();
    return `${nombre} ${apellido}`;
}

const nombreCompleto = obtenerCompleto();
console.log("nombre completo: ", nombreCompleto);