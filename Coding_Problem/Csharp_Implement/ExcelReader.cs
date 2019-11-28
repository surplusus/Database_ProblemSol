using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;

namespace Csharp_Implement
{
    class ExcelReader
    {
        static void Main(string[] args)
        {
            Application application = new Application();
            // 새로 만들기
            //Workbook workbook = application.Workbooks.Add();
            Workbook workbook = application.Workbooks.Open(Filename: @"C:\aa.xls");
            Worksheet worksheet1 = workbook.Worksheets.Item["Sheet1"];

            string[,] data = new string[3, 3];

            string[] namedata = new string[3];
            string[] pricedata = new string[3];
            string[] expressiondata = new string[3];

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    Range range = worksheet1.Cells[r + 1, c + 1];
                    var dynamic = range.Value;
                    Console.WriteLine($"{dynamic}");
                    //data[r, c] = range.Value;
                }
            }

            foreach (var item in data)
            {
                Console.WriteLine($"{item }");
            }
        }

    }
}