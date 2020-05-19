import unittest
from selection_sort import selection_sort
from bubble_sort import bubble_sort

class TestSelectionSort(unittest.TestCase):
  def test_empty_list(self):
    self.assertEqual(selection_sort([]), [])

  def test_sorted_list(self):
    self.assertEqual(selection_sort([1,2,3,4,5]), [1,2,3,4,5])

  def test_unsorted_list(self):
    self.assertEqual(selection_sort([5,4,3,0,1]), [0,1,3,4,5])

class TestBubbleSort(unittest.TestCase):
  def test_empty_list(self):
    self.assertEqual(bubble_sort([]), [])

  def test_sorted_list(self):
    self.assertEqual(bubble_sort([1,2,3,4,5]), [1,2,3,4,5])

  def test_unsorted_list(self):
    self.assertEqual(bubble_sort([5,4,3,0,1]), [0,1,3,4,5])

if __name__ == "__main__":
  unittest.main()
