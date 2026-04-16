package ejemplo2;

public class Barcelona implements IEquipo{

	private String fechaClub;
	
	public Barcelona()
	{
		
	}

	public String getFechaClub() {
		return fechaClub;
	}

	public void setFechaClub(String fechaClub) {
		this.fechaClub = fechaClub;
	}

	@Override
	public String toString() {
		return "Barcelona [fechaClub=" + fechaClub + "]";
	}

	@Override
	public String devuelveInformacion() {
		return "Equipo barcelona....";
	}
	
	
	
}
