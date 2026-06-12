
//Agregar Medico - Agregar Paciente
function validarDni(modificarDom, entradaYValidacion) {
  var valor = entradaYValidacion.Value.trim(); //otra forma de hacer lo mismo
  var regexDni = new RegExp("^[1-9][0-9]{6,7}$");

  if (valor === "") {//hay que usar ValidateEmptyText="true" en adicion 
    modificarDom.innerHTML = "Debe ingresar un Dni";
    entradaYValidacion.IsValid = false;
    return;
  }

  if (!regexDni.test(valor)) {
    modificarDom.innerHTML = "Error: el DNI debe tener entre 7 y 8 caracteres y no empezar con 0  ";
    entradaYValidacion.IsValid = false;
    return;
  }
  entradaYValidacion.IsValid = true;
}

//Agregar Medico
function validarLegajo(source, args) { //source => la etiqueta <asp:CustomValidator ID="cvLegajo" se convierte en HTML de tipo div o SPAN => el ErrorMessage pasa a ser SPAN
  var txtLegajo = document.getElementById(source.controltovalidate); // Obtiene el TextBox
  var regex = new RegExp("^[a-zA-Z][0-9]{3}$"); 

  if (txtLegajo.value.trim() === "") {
    source.innerHTML = "Debe ingresar un Legajo";
    args.IsValid = false;
    return;
  }

  if (!regex.test(txtLegajo.value)) {
    source.innerHTML = "Error: el Legajo debe tener 4 caracteres (L001)"; // Cambia el mensaje estático
    args.IsValid = false;
    return;
  }

  // 3. Si llega aquí, es válido
  args.IsValid = true;
}

//Agregar y Editar Medico | Agregar y Editar Paciente
function validarNomApeNac(source, args) {
  var valor = args.Value.trim();
  var regexNomApeNac = new RegExp("^[a-zA-ZáéíóúÁÉÍÓÚñÑ\\s]+$");// la s permite espacios como "Juan Pérez"

  var idControl = source.controltovalidate; //ID del control que se está validando (ej: "txtNombre" o "txtApellido")


  if (valor === "") {
    if (idControl && idControl.includes("txtNombre")) {//idControl es por si viene null o undefined (falso) => asi no se rompe
      source.innerHTML = "Debe ingresar el Nombre.";
    }
    else if (idControl && idControl.includes("txtApellido")) { // USAR ELSE IF
      source.innerHTML = "Debe ingresar el Apellido.";
    }
    else if (idControl && idControl.includes("txtNacionalidad")) {
      source.innerHTML = "Debe ingresar una Nacionalidadaaa.";
    }
    else { // USAR ELSE PARA EL MENSAJE POR DEFECTO
      source.innerHTML = "Debe completar el campo.";
    }

    args.IsValid = false;
    return;
  }

  if (!regexNomApeNac.test(valor)) {
    source.innerHTML = "Solo se permiten letras y espacios.";
    args.IsValid = false;
    return;
  }

  args.IsValid = true;
}

//Agregar y Editar Medico | Agregar y Editar Paciente
function validarCorreo(source, args) {
  var valor = args.Value.trim(); //otra forma de hacer lo mismo
  //var regexMail = new RegExp("^[a-zA-Z0-9ñ._-]+@[a-zA-Z0-9]+\\.([a-zA-Z]{3,4})(\\.([a-zA-Z]{2,3}))?$");
  var regexMail = /^[a-zA-Z0-9ñ._-]+@[a-zA-Z0-9]+\.([a-zA-Z]{3,4})(\.([a-zA-Z]{2,3}))?$/; //JS le gusta este patron ya que con /.../ ya se prepara para guardar un REGEX

  if (valor === "") {
    source.innerHTML = "Debe ingresar un Mail";
    args.IsValid = false;
    return;
  }

  if (!regexMail.test(valor)) {
    source.innerHTML = "Error: el mail debe tener un formato valido (ejemplo@gmail.com)"; // Cambia el mensaje estático
    args.IsValid = false;
    return;
  }

  args.IsValid = true;
}

//Agregar y Editar Medico | Agregar y Editar Paciente
function validarTelefono(source, args) {
  var valor = args.Value.trim(); //otra forma de hacer lo mismo
  var regexTel = /^[+]?[(]?[0-9]{1,4}[)]?[0-9\s.-]+$/;

  if (valor === "") {
    source.innerHTML = "Debe ingresar un Telefono";
    args.IsValid = false;
    return;
  }

  if (!regexTel.test(valor)) {
    source.innerHTML = "Error: el telefono debe tener un formato valido (+549 11 2345-6789 o 11 234 567)"; // Cambia el mensaje estático
    args.IsValid = false;
    return;
  }

  args.IsValid = true;

}

//Agregar y Editar Medico | Agregar y Editar Paciente
// <asp: CustomValidator ID="cvEdadMinima" ControlToValidate="txtFechaNacimiento" ClientValidationFunction="validarEdadMedico" CssClass="error-validacion" ValidateEmptyText="true" />
function validarEdad(validadorEdadMininma, comunicacionBidireccional) { //comunicacionBidireccional tiene 2 parametros => CIN que es .Value y el rtn que es bool .IsValid
  //fecha nac
  var iso8601Str = comunicacionBidireccional.Value;// Guarda "2025-11-25" .........valor string => recibe el valor de <asp:TextBox ID="txtFechaNacimiento">
  var fechaNacimiento = new Date(iso8601Str); //constructor
  fechaNacimiento.setHours(0, 0, 0); // 0 hs, 0 min, 0 seg

  if (iso8601Str.trim() == "") {
    comunicacionBidireccional.IsValid = false;//esto es para que se bloque el SubMit y al dar al btn Guardar  no se mande el form por que el Page_IsValid esta en False
    validadorEdadMininma.innerHTML = "Seleccione una fecha"; // el innherHTML manipula el DOM (Document Object Model) dando el texto que quiero al CV
    return;
  }

  //fecha hoy
  var hoy = new Date();
  hoy.setHours(0, 0, 0);
  var anioActualMenosMayoriaEdad = hoy.getFullYear() - 18;

  var fechaLimiteParaSerMayor = new Date(anioActualMenosMayoriaEdad, hoy.getMonth(), hoy.getDate());
  fechaLimiteParaSerMayor.setHours(0, 0, 0); // hora 00:00:00

  if (fechaNacimiento >= fechaLimiteParaSerMayor || fechaNacimiento > hoy) {
    comunicacionBidireccional.IsValid = false; // no pasa validacion
    validadorEdadMininma.innerHTML = "Debe ser mayor de 18 años y la fecha no debe ser futura.";
  } else {
    comunicacionBidireccional.IsValid = true;
  }
}


//Agregar Editar Medico
function validarCheckBox(source, args) {
    var cblDias = document.getElementById(cblDiasClientId);

    if (cblDias) {
        var checkboxes = cblDias.getElementsByTagName("input");
        var isChecked = false;

        for (var i = 0; i < checkboxes.length; i++) {
            if (checkboxes[i].type === "checkbox" && checkboxes[i].checked) {
                isChecked = true;
                break;
            }
        }
        args.IsValid = isChecked;
    } else {
        args.IsValid = false;
    }
}

function validarUsuario(source, args) {
    var valor = args.Value.trim();

    // Expresión regular: letras, números, puntos y guiones bajos
    var regexUsuario = /^[a-zA-Z0-9._]+$/;

    if (valor === "") {
        source.innerHTML = "Ingrese nombre de usuario";
        args.IsValid = false;
        return;
    }

    if (!regexUsuario.test(valor)) {
        source.innerHTML = "Solo se permiten letras, números, puntos (.) o guiones bajos (_)";
        args.IsValid = false;
        return;
    }

    args.IsValid = true;
}

function validarContrasena(source, args) {
    var valor = args.Value.trim();

    if (valor === "") {
        source.innerHTML = "Ingrese contraseña";
        args.IsValid = false;
        return;
    }

    var regexPass = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\*\._])[A-Za-z\d\*\._]{6,30}$/;

    if (!regexPass.test(valor)) {
        source.innerHTML = "Debe tener al menos una mayúscula, una minúscula, un número y un caracter especial (* . _)";
        args.IsValid = false;
        return;
    }

    args.IsValid = true;
}

