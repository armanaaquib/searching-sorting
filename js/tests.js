const assert = require('assert');
const {
  selectionSort,
  bubbleSort,
  insertionSort,
  quickSort,
} = require('./sort');

describe('selectionSort', function () {
  it('should sort empty list', function () {
    const list = [];
    selectionSort(list);
    assert.deepStrictEqual(list, []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    selectionSort(list);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    selectionSort(list);
    assert.deepStrictEqual(list, [0, 1, 2, 3, 5]);
  });
});

describe('bubbleSort', function () {
  it('should sort empty list', function () {
    const list = [];
    bubbleSort(list);
    assert.deepStrictEqual(list, []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    bubbleSort(list);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    bubbleSort(list);
    assert.deepStrictEqual(list, [0, 1, 2, 3, 5]);
  });
});

describe('insertionSort', function () {
  it('should sort empty list', function () {
    const list = [];
    insertionSort(list);
    assert.deepStrictEqual(list, []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    insertionSort(list);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    insertionSort(list);
    assert.deepStrictEqual(list, [0, 1, 2, 3, 5]);
  });
});

describe('quickSort', function () {
  it('should sort empty list', function () {
    const list = [];
    quickSort(list, -1, -1);
    assert.deepStrictEqual(list, []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    quickSort(list, 0, 4);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    quickSort(list, 0, 4);
    assert.deepStrictEqual(list, [0, 1, 2, 3, 5]);
  });
});
