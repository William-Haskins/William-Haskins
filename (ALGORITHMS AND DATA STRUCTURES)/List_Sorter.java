package sorting_algorithm;

import java.util.*;
import sorting_algorithm.*;

public class List_Sorter {
	
	public static int passCounter;
	
	public static void sortSelection(List<Integer> theList) {
		//Initializing variables. . .
		String query = new String("x");
		Scanner myObj = new Scanner(System.in);
		passCounter = 0;
		//
		//Opening dialogue. . .
		System.out.println("Please select a sorting method.");
		System.out.println("Enter 'reverse' to reverse the list.");
		System.out.println("Enter 'bubble' to bubblesort the list.");
		System.out.println("Enter 'quick' to quicksort the list.");
		System.out.println("Enter 'quit' to exit.");
		query = myObj.nextLine();
		//
		
		//Setting dialogue responses. . .
		if (query.equals("reverse")) {
			List_Sorter.reverseList(theList);
		}
		else if (query.equals("bubble")) {
			System.out.println("Sorting the list with bubbles. . .");
			List_Sorter.bubbleSortList(theList);
		}
		else if (query.equals("quick")) {
			System.out.println("Sorting the list quickly. . .");
			List_Sorter.quickSortList(theList, 0, (theList.size() - 1));
			
			System.out.println("It took " + passCounter + " cycles but the list is now sorted.");
			List_Sorter.readTheList(theList);
			System.out.println();
			List_Filler.listSelection(theList);
		}
		else if (query.equals("quit") || query.equals("q")) {
			System.out.println("Goodbye.");
			return;
		}
		else {
			List_Sorter.sortSelection(theList);
		}
		//
	}
	
	public static void reverseList(List<Integer> theList) {
		List<Integer> holdingList = new ArrayList<Integer>();
		int j = theList.size() - 1;
		int i = 0;
		
		System.out.println("Reversing the list. . .");
		holdingList.addAll(theList);
		System.out.print("[ ");
		for (i = 0; i < theList.size(); i++) {
			
			theList.set(i, holdingList.get(j));

			System.out.print(theList.get(i) + " ");
			j--;
		}
		System.out.print("]\n\n");
		List_Filler.listSelection(theList);
	}
	
	public static void bubbleSortList(List<Integer> theList) {
		int sortedCheck = 0;
		int i = 0;
		int holderVariable = 0;
		
		while (sortedCheck != 1) {
			
			sortedCheck = 1;
			for (i = 0; i < (theList.size() - 1); i++) {
				if (theList.get(i) > theList.get(i + 1)) {
					holderVariable = theList.get(i);
					theList.set(i, theList.get(i + 1));
					theList.set(i + 1, holderVariable);
					sortedCheck = 0;
				}
				passCounter++;
			}
		}
		System.out.println("It took " + passCounter + " cycles but the list is now sorted.");
		i = 0;
		System.out.print("[ ");
		for (i = 0; i < theList.size(); i++) {
			System.out.print(theList.get(i) + " ");
		}
		System.out.print("]\n\n");
		List_Filler.listSelection(theList);
	}
	
	public static void quickSortList(List<Integer> theList, int lowIndex, int highIndex) {

		if (lowIndex >= highIndex) {
			return;
		}
		
		int pivotPointer = theList.get(highIndex);
		
		int leftPointer = lowIndex;
		int rightPointer = highIndex;
		
		while (leftPointer < rightPointer) {
			
			while (theList.get(leftPointer) <= pivotPointer && leftPointer < rightPointer) {
				leftPointer++;
				passCounter++;
			}
			
			while (theList.get(rightPointer) >= pivotPointer && leftPointer < rightPointer) {
				rightPointer--;
				passCounter++;
			}
			swaper(theList, leftPointer, rightPointer);
		}	
		swaper(theList, leftPointer, highIndex);
		
		///////////////////////////// LOW HALF
		List_Sorter.quickSortList(theList, lowIndex, leftPointer - 1);
		//////////////////////////// HIGH HALF
		List_Sorter.quickSortList(theList, leftPointer + 1, highIndex);
		
	}
	public static void swaper(List<Integer> theList, int num1, int num2) {
		int holderVariable = theList.get(num1);
		theList.set(num1, theList.get(num2));
		theList.set(num2, holderVariable);
	}
	public static void readTheList(List<Integer> theList) {
		System.out.print("[ ");
		for (int i = 0; i < theList.size(); i++) {
			System.out.print(theList.get(i) + " ");
		}
		System.out.print("]\n");
	}
}		


