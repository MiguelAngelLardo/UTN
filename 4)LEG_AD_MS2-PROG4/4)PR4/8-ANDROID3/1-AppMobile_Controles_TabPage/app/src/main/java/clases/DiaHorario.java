package clases;
public class DiaHorario {

    private String horario;
    private String dia;

    public DiaHorario()
    {
    }
    public DiaHorario(String horario, String dia) {
        this.horario = horario;
        this.dia = dia;
    }

    public String getHorario() {
        return horario;
    }

    public void setHorario(String horario) {
        this.horario = horario;
    }

    public String getDia() {
        return dia;
    }

    public void setDia(String dia) {
        this.dia = dia;
    }

    @Override
    public String toString() {
        return horario + " (" + dia + ")";
    }
}
