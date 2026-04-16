package Ejercicio1;

import java.util.Objects;

public class Profesor extends Empleado implements Comparable {
	
	private String cargo;
	private int antiguedadDocente;

	public Profesor(){
		super();
	}
	
	public Profesor(int id, String nombre, int edad, String cargo, int antiguedadDocente) {
		super(id,nombre, edad);
		this.cargo = cargo;
		this.antiguedadDocente = antiguedadDocente;
	}

	public String getCargo() {return cargo;}
	public void setCargo(String cargo) {this.cargo = cargo;}

	public int getAntiguedadDocente() {return antiguedadDocente;}
	public void setAntiguedadDocente(int antiguedadDocente) {this.antiguedadDocente = antiguedadDocente;}
	
	@Override
	public String toString()
	{
		return super.toString() + "Cargo: " + cargo + "Antiguedad: " + antiguedadDocente;
	}

	@Override
	public int hashCode() {
		return Objects.hash(antiguedadDocente, cargo);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Profesor other = (Profesor) obj;
		return antiguedadDocente == other.antiguedadDocente && Objects.equals(cargo, other.cargo);
	}
	
	@Override
	public int compareTo(Object o) 
	{
		return 0;		
	}
	
}
