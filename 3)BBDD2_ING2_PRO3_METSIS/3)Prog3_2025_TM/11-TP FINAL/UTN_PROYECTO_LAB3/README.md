# 🏥 Sistema de Gestión para Clínica Médica  
**Programación III – UTN Facultad Regional General Pacheco**  
**Grupo 04 – Año 2025**  
**Arquitectura en 3 Capas**

---

## 📌 Descripción del Proyecto
Este proyecto consiste en el desarrollo de un **sistema de gestión para una clínica médica**, implementado con **arquitectura en tres capas** (Presentación, Negocio y Datos).

El sistema permite la administración de pacientes, médicos y turnos.  
Incluye dos tipos de usuarios: **Administrador** y **Médico**.

Las localidades, provincias, especialidades y usuarios administradores se encuentran precargados en la base de datos.

---

## 👥 Roles del Sistema

---

## 🔹 Usuario Administrador

### ✔ ABML de Pacientes
Cada paciente posee:
- DNI  
- Nombre  
- Apellido  
- Sexo  
- Nacionalidad  
- Fecha de nacimiento  
- Dirección  
- Localidad  
- Provincia  
- Correo electrónico  
- Teléfono  

### ✔ ABML de Médicos
Cada médico posee:
- Legajo  
- DNI  
- Nombre  
- Apellido  
- Sexo  
- Nacionalidad  
- Fecha de nacimiento  
- Dirección  
- Localidad  
- Provincia  
- Correo electrónico  
- Teléfono  
- Especialidad  
- Días y horarios de atención  
- Usuario y contraseña del sistema (editable)

> Un médico solo puede tener **una especialidad**.

### ✔ Asignación de Turnos
El administrador podrá seleccionar:
- Especialidad  
- Médico  
- Día  
- Horario  
- Paciente  

Condiciones:
- Cada turno dura **1 hora**  
- Un médico **no puede tener dos turnos** el mismo día y a la misma hora  

### ✔ Informes
El sistema debe generar **informes procesados**, no simples listados.

Ejemplo:
- Entre enero 2024 y febrero 2024:  
  - 30% ausentes  
  - 70% presentes  
  - Detalle de personas presentes y ausentes  

---

## 🔹 Usuario Médico

### ✔ Visualización de Turnos
El médico puede ver todos sus turnos asignados con:
- Paciente  
- Fecha  
- Horario  
- Filtros y búsquedas  

### ✔ Registrar Presentismo
El médico podrá:
- Marcar **Presente** o **Ausente**  
- Agregar una **observación** para los turnos presentes  

---

## 🔐 Login del Sistema
Ambos roles acceden mediante pantalla de **login**.  
En todas las pantallas se visualiza el **nombre del usuario logueado**.

---

## 🧱 Arquitectura del Proyecto: 3 Capas

### 1. **Capa de Presentación**
Interfaz, vistas, formularios.

### 2. **Capa de Negocio**
Reglas de negocio, validaciones, lógica de turnos, informes.

### 3. **Capa de Datos**
Acceso a base de datos, consultas, entidades, procedimientos almacenados.

---

## 🛠️ Tecnologías Utilizadas
- C# / .NET  
- SQL Server  
- WebForms / MVC 
- Arquitectura en 3 Capas  

