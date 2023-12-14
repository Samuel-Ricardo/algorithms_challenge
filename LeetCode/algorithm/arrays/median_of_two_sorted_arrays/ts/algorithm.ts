//impl 1

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const result = nums1.concat(nums2).sort((a, b) => a - b);
  const middle = result.length / 2 - 1;
  const median =
    result.length % 2 !== 0
      ? result[Math.round(middle)] //impar
      : (result[middle] + result[middle + 1]) / 2; //par

  return median;
}

// impl impl2

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const result = nums1.concat(nums2);
  quickSort(result, 0, result.length - 1);
  const middle = result.length / 2 - 1;
  const median =
    result.length % 2 !== 0
      ? result[Math.round(middle)] //impar
      : (result[middle] + result[middle + 1]) / 2; //par

  return median;
}

function quickSort(arr: number[], start: number, end: number) {
  if (start < end) {
    let pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
}

const partition = (arr: number[], start: number, end: number) => {
  let pivot = end;

  let i = start - 1;
  let j = start;

  while (j < pivot) {
    if (arr[j] > arr[pivot]) {
      j++;
    } else {
      i++;
      swap(arr, j, i);
      j++;
    }
  }

  swap(arr, i + 1, pivot);
  return i + 1;
};

const swap = (arr: number[], firstIndex: number, secondIndex: number) => {
  let temp = arr[firstIndex];
  arr[firstIndex] = arr[secondIndex];
  arr[secondIndex] = temp;
};
