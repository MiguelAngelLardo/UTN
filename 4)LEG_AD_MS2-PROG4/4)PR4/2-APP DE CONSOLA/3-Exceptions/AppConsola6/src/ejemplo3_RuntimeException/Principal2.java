package ejemplo3_RuntimeException;

import javax.swing.JOptionPane;

public class Principal2 {

	public static void main(String[] args) {
	
		try
		{
		int num1 = Integer.parseInt(JOptionPane.showInputDialog("Ingrese num1"));	
		int num2 = Integer.parseInt(JOptionPane.showInputDialog("Ingrese num2"));	
		int res = num1/num2;
		}
		catch(ArithmeticException e)
		{
			System.out.println("Error por división por cero");
		}
		catch(NumberFormatException e)
		{
			System.out.println("Error se necesita formato numérico");
		} 
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			
		}
	}
}
