const assert = require('assert');
const {
  selectionSort,
  bubbleSort,
  insertionSort,
  quickSort,
  quickNotInPlaceSort,
  jsSort,
} = require('./sort');

const { linearSearch, binarySearch } = require('./search');

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

describe('quickNotInPlaceSort', function () {
  it('should sort empty list', function () {
    const list = [];
    assert.deepStrictEqual(quickNotInPlaceSort(list), []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    assert.deepStrictEqual(quickNotInPlaceSort(list), [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    assert.deepStrictEqual(quickNotInPlaceSort(list), [0, 1, 2, 3, 5]);
  });
});

describe('jsSort', function () {
  it('should sort empty list', function () {
    const list = [];
    jsSort(list);
    assert.deepStrictEqual(list, []);
  });

  it('should sort sorted list', function () {
    const list = [1, 2, 3, 4, 5];
    jsSort(list);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort rev sorted list', function () {
    const list = [5, 4, 3, 2, 1];
    jsSort(list);
    assert.deepStrictEqual(list, [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    const list = [5, 2, 3, 1, 0];
    jsSort(list);
    assert.deepStrictEqual(list, [0, 1, 2, 3, 5]);
  });
});

describe('linearSearch', function () {
  it('should return -1 if list is empty', function () {
    assert.strictEqual(linearSearch([], 1), -1);
  });

  it('should return pos if element is in the list', function () {
    assert.strictEqual(linearSearch([1, 2, 3, 4, 5], 1), 0);
  });

  it('should return pos of first occurrence if element is in the list', function () {
    assert.strictEqual(linearSearch([3, 2, 1, 4, 1], 1), 2);
  });

  it('should return -1 if element is not in the list', function () {
    assert.strictEqual(linearSearch([3, 2, 1, 4, 1], 5), -1);
  });
});

describe('binarySearch', function () {
  it('should return -1 if list is empty', function () {
    assert.strictEqual(binarySearch([], 1), -1);
  });

  it('should return -1 if element is not in the left the side of the list', function () {
    assert.strictEqual(binarySearch([1, 2, 3, 4, 5], 0), -1);
  });

  it('should return -1 if element is not in the right the side of the list', function () {
    assert.strictEqual(binarySearch([1, 2, 3, 4, 5], 6), -1);
  });

  it('should return pos if element is in the left side of the list', function () {
    assert.strictEqual(binarySearch([1, 2, 3, 4, 5], 1), 0);
  });

  it('should return pos if element is in the right side of the list', function () {
    assert.strictEqual(binarySearch([1, 2, 3, 4, 5], 5), 4);
  });

  it('should return pos of first occurrence if element is in the list', function () {
    assert.strictEqual(binarySearch([1, 2, 3, 4, 4], 4), 3);
  });
});
