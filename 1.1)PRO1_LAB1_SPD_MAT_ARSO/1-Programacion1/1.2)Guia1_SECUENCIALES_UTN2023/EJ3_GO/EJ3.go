package main
import "fmt"

const (
	FIXED_SALARY  = 15000
	AWARD_PER_CAR = 2000
)

func main(){
	var counter int
	var totalPaid float32

	print("Add the counter of the car sold: ")
	fmt.Scan(&counter)

	totalPaid = (AWARD_PER_CAR * float32(counter)) + float32(FIXED_SALARY)

	fmt.Printf("The total salary is: $%.2f", totalPaid)
}
