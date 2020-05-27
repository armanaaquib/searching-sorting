import unittest
from sort import (selection_sort,
                  bubble_sort,
                  insertion_sort,
                  quick_not_in_place_sort)


class TestSelectionSort(unittest.TestCase):
    def test_empty_list(self):
        l = []
        selection_sort(l)
        self.assertEqual(l, [])

    def test_sorted_list(self):
        l = [1, 2, 3, 4, 5]
        selection_sort(l)
        self.assertEqual(l, [1, 2, 3, 4, 5])

    def test_unsorted_list(self):
        l = [5, 6, 3, 0, 1]
        selection_sort(l)
        self.assertEqual(l, [0, 1, 3, 5, 6])


class TestBubbleSort(unittest.TestCase):
    def test_empty_list(self):
        l = []
        bubble_sort(l)
        self.assertEqual(l, [])

    def test_sorted_list(self):
        l = [1, 2, 3, 4, 5]
        bubble_sort(l)
        self.assertEqual(l, [1, 2, 3, 4, 5])

    def test_unsorted_list(self):
        l = [5, 6, 3, 0, 1]
        bubble_sort(l)
        self.assertEqual(l, [0, 1, 3, 5, 6])


class TestInsertionSort(unittest.TestCase):
    def test_empty_list(self):
        l = []
        insertion_sort(l)
        self.assertEqual(l, [])

    def test_sorted_list(self):
        l = [1, 2, 3, 4, 5]
        insertion_sort(l)
        self.assertEqual(l, [1, 2, 3, 4, 5])

    def test_unsorted_list(self):
        l = [5, 6, 3, 0, 1]
        insertion_sort(l)
        self.assertEqual(l, [0, 1, 3, 5, 6])


class TestQuickNotInPlaceSort(unittest.TestCase):
    def test_empty_list(self):
        self.assertEqual(quick_not_in_place_sort([]), [])

    def test_sorted_list(self):
        self.assertEqual(quick_not_in_place_sort(
            [1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_unsorted_list(self):
        self.assertEqual(quick_not_in_place_sort(
            [5, 6, 3, 0, 1]), [0, 1, 3, 5, 6])


if __name__ == "__main__":
    unittest.main()
