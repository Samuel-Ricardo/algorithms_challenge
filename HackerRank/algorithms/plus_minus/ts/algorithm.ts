"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString: string = "";
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on("data", function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on("end", function (): void {
  inputLines = inputString.split("\n");
  inputString = "";

  main();
});

function readLine(): string {
  return inputLines[currentLine++];
}

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

function plusMinus(arr: number[]): void {
  let positives = 0;
  let negatives = 0;
  let zeros = 0;
  const total = arr.length;

  arr.forEach((num) => {
    if (num > 0) {
      positives++;
      return;
    }

    if (num < 0) {
      negatives++;
      return;
    }

    zeros++;
  });

  console.log((positives / total).toFixed(6));
  console.log((negatives / total).toFixed(6));
  console.log((zeros / total).toFixed(6));
}

function main() {
  const n: number = parseInt(readLine().trim(), 10);

  const arr: number[] = readLine()
    .replace(/\s+$/g, "")
    .split(" ")
    .map((arrTemp) => parseInt(arrTemp, 10));

  plusMinus(arr);
}
