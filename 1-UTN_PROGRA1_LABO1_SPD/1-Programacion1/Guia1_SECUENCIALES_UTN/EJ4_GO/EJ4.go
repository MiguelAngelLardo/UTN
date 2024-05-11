package main
import "fmt"

func main(){
	var totalSeat int
	var soldSeat int
	var percentageOccupied float32
	var percentageEmpty float32 

	print("Add the number of the total seat: ")
	fmt.Scan(&totalSeat)
	print("How many seats has already been sold select: ")
	fmt.Scan(&soldSeat)

	percentageOccupied = float32(soldSeat) / float32(totalSeat) * 100
	percentageEmpty = 100 - percentageOccupied

	fmt.Printf("Percentage Occuped %.2f%% and Percentage empty: %.2f%%", percentageOccupied, percentageEmpty)
}
