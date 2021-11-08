package leetcode

import (
	"reflect"
	"testing"
)

func TestProductExceptSelf(t *testing.T) {

	t.Run("Test Product Except Self", func(t *testing.T) {
		numbers := []int{4, 2, 3, 4}

		got := productExceptSelf(numbers)
		want := []int{24, 48, 32, 24}

		if !reflect.DeepEqual(got, want) {
			t.Errorf("got %v want %v", got, want)
		}
	})
}
