using System.Collections.Generic;
//Добавить степень

namespace lr_analyzer
{
	public static class ParserConstants
	{
		public static readonly Dictionary<char, string[]> Table = new Dictionary<char, string[]>()
		{
			{'E', new[] {"s1", "", "", "", "", "", "", "", "s9", "", "", ""}},
			{'T', new[] {"s4", "", "s3", "", "", "", "", "", "s4", "", "", ""}},
			{'f', new[] {"s7", "", "s7", "", "", "s6", "", "", "s7", "", "", ""}},
			{'+', new[] {"", "s2", "", "r0", "r1", "", "r2", "r3", "", "s2", "r4", "r5"}},
			{'*', new[] {"", "", "", "s5", "s5", "", "r2", "r3", "", "", "r4", "r5"}},
			{'(', new[] {"s8", "", "s8", "", "", "s8", "", "", "s8", "", "", ""}},
			{')', new[] {"", "s11", "", "r0", "r1", "", "r2", "r3", "", "s3", "r4", "r5"}},
			{'x', new[] {"s11", "", "s11", "", "", "s11", "", "", "s11", "", "", ""}},
			{';', new[] {"", "acc", "", "r0", "r1", "", "r2", "r3", "", "", "r4", "r5"}}
		};
		
		public static readonly Dictionary<string, string> Rule = new Dictionary<string, string>()
		{
			{"E1", "E+T"},
			{"E0", "T"},
			{"T1", "T*f"},
			{"T0", "f"},
			{"f1", "(E)"},
			{"f0", "x"}
		};
	}
}