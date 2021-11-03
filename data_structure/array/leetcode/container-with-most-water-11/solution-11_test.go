package main

import "testing"

func TestMaxArea(t *testing.T) {

	t.Run("Case_1", func(t *testing.T) {
		numbers := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}

		got := maxArea(numbers)
		want := 49

		if got != want {
			t.Errorf("got %d want %d given, %v", got, want, numbers)
		}
	})

	t.Run("Case_2", func(t *testing.T) {
		numbers := []int{1, 1}

		got := maxArea(numbers)
		want := 1

		if got != want {
			t.Errorf("got %d want %d given, %v", got, want, numbers)
		}
	})

}
