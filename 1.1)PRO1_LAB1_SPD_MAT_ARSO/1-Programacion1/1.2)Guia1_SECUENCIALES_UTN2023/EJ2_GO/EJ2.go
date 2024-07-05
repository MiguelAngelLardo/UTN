package main
import "fmt" //es para entrada y salida de formato

func main (){
	var n1 int
	var n2 int
	var aux int

	fmt.Print("Enter the first number : ")
	fmt.Scan(&n1)
	fmt.Print("Enter the second number: ")
	fmt.Scan(&n2)

	aux = n1
	n1 = n2 
	n2 = aux 

	println("\nNow number one is:", int(n1), "and now number two is:", int(n2))
}

