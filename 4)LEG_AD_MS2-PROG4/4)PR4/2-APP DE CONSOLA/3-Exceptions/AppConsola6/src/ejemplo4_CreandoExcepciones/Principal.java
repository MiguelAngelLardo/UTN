package ejemplo4_CreandoExcepciones;

import javax.swing.JOptionPane;

public class Principal {
	
	
	public static void main(String[] args) {
		
		try
		{
		String correo = JOptionPane.showInputDialog("Ingrese correo electronico: ");
	    Mail.validarMail(correo);
		}
		catch(FaltaArrobaException e)
		{
			System.out.println("Error falta arroba ");
			e.printStackTrace();
		}
		catch(FaltaPuntoException e)
		{
			System.out.println("Error FaltaPuntoException ");
			e.printStackTrace();
		}
	}
}
