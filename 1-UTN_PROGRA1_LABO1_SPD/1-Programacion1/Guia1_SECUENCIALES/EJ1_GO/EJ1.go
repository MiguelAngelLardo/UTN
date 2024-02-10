package main
import "fmt" //es para entrada y salida de formato

func main (){
	var hs int
	var rate float64
	fmt.Print("Add the amount of hours: ")
	fmt.Scan(&hs)

	fmt.Print("Add the rate per hours: ")
	fmt.Scan(&rate)

	var salary float64 = float64(hs) * rate
	fmt.Println("\nYour salary is:", salary)
}