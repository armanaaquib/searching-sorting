const assert = require('assert');
const { selectionSort } = require('./selectionSort');
const { bubbleSort } = require('./bubbleSort');
const { insertionSort } = require('./insertionSort');

describe('selectionSort', function () {
  it('should sort empty list', function () {
    assert.deepStrictEqual(selectionSort([]), []);
  });

  it('should sort sorted list', function () {
    assert.deepStrictEqual(selectionSort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    assert.deepStrictEqual(selectionSort([5, 2, 3, 1, 0]), [0, 1, 2, 3, 5]);
  });
});

describe('bubbleSort', function () {
  it('should sort empty list', function () {
    assert.deepStrictEqual(bubbleSort([]), []);
  });

  it('should sort sorted list', function () {
    assert.deepStrictEqual(bubbleSort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    assert.deepStrictEqual(bubbleSort([5, 2, 3, 1, 0]), [0, 1, 2, 3, 5]);
  });
});

describe('insertionSort', function () {
  it('should sort empty list', function () {
    assert.deepStrictEqual(insertionSort([]), []);
  });

  it('should sort sorted list', function () {
    assert.deepStrictEqual(insertionSort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    assert.deepStrictEqual(insertionSort([5, 2, 3, 1, 0]), [0, 1, 2, 3, 5]);
  });
});
