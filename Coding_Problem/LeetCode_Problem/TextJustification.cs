using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace algorithm {
    public class TextJustification {
        public static string MinRemoveToMakeValid(string s) {
            Stack<int> openSt = new Stack<int>();
            Stack<int> closeSt = new Stack<int>();
            int flagOpen = 0;
            string result = String.Empty;
            for (int i = 0; i < s.Length; i++) {
                if (s[i] == '(') {
                    openSt.Push(i);
                    flagOpen++;
                    result += '(';
                } else if (s[i] == ')') {
                    if (openSt.Count != 0) {
                        flagOpen--;
                        openSt.Pop();
                        result += ')';
                    } else {
                        result += ' ';
                    }
                } else {
                    result += s[i];
                }
                
            }
// 예외처리
            while (openSt.Count != 0) {
                flagOpen--;
                int openIndex = openSt.Pop();
                result = result.Remove(openIndex,1);
            }
            
            return result = result.Replace(" ", string.Empty);
        }
    }
}