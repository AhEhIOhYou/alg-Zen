using System;
using System.Collections.Generic;
using System.Linq;

namespace lr_analyzer
{
	internal static class Program
	{
		private static string GetActionName(int state, char symbol)
		{
			var l = ParserConstants.Table[symbol];
			if (l == null)
			{
				return "Unknown symbol";
			}
			var action = l[state];
			
			if (action == "acc")
				return "end";
			
			action = action.Substring(0, 1);

			switch (action)
			{
				case "s":
					return "shift";
				case "r":
					return "reduce";
				default:
					return "Something went wrong";
			}

		}
		private static int GetActionNumber(int state, char symbol)
		{
			var l = ParserConstants.Table[symbol];
			if (l == null)
			{
				return -1;
			}
			var action = l[state];

			return Int32.Parse(action.Substring(1));
		}
		private static string GetReplace(string str)
		{
			string add = "";
			while (str.Length != 0)
			{
				foreach (var item in ParserConstants.Rule)
				{
					if (item.Value == str)
					{
						return add + item.Key[0];
					}
				}

				add += str[0];
				str = str.Remove(0, 1);
			}

			return "Replace not found";
		}
		private static string FormatStateStack(Stack<int> stk)
		{
			string result = "";
			Stack<int> states = new Stack<int>(stk);

			while (states.Count != 0)
			{
				result += states.Pop() + " ";
			}
			
			return result;
		}

		private static void LR(string inputStr)
		{
			inputStr += ";";

			Stack<int> stateStack = new Stack<int>();
			string readyForm = "";

			//Подготовка к первому шагу
			stateStack.Push(0);
			char token = inputStr[0];

			Console.WriteLine("{0,20}  |  {1, 20}  |", "State stack", "Result");
			
			while (true)
			{
				var state = stateStack.Peek();
				var doing = GetActionName(state, token);
				
				var tmp = FormatStateStack(stateStack);

				var tmp2 = readyForm + inputStr;
				
				Console.WriteLine("{0,20}  |  {1, 20}  |", tmp , tmp2);

				if (doing == "end")
				{
					break;
				}

				var actNum = GetActionNumber(state, token);
				stateStack.Pop();

				if (doing == "shift")
				{
					stateStack.Push(actNum);
					readyForm += token;
					inputStr = inputStr.Remove(0, 1);
					token = inputStr[0];
				}
				else if (doing == "reduce")
				{
					readyForm = GetReplace(readyForm);
					actNum = GetActionNumber(actNum, readyForm.Last());
					stateStack.Push(actNum);
				}
			}
		}

		public static void Main(string[] args)
		{
			while (true)
			{
				Console.Write("String: ");
				var str = Console.ReadLine();
				if (str != null)
					LR(str);
				else
					break;
			}
		}
	}
}