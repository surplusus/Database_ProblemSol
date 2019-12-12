using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Csharp_Implement
{
    class UnitySoundDataExcelFileReader
    {
        static void Main(string[] args)
        {
            Application app = new Application();
            string savePath = Directory.GetCurrentDirectory();
            Workbook workbook = app.Workbooks.Open(Filename: savePath + "\\SoundData.xlsx");
            Worksheet worksheet = workbook.Worksheets.Item["Sheet1"];

            Range range = worksheet.Range["A2:D3"];
            object[,] values = range.Value;
            workbook.Close();

            List<SerialData> datas = new List<SerialData>();

            // values의 index는 1부터 시작
            for (int r = 1; r < values.GetLength(0); ++r)
            {
                SerialData buffer = new SerialData();
                buffer.name = values[r, 1].ToString();
                buffer.path = values[r, 2].ToString();
                buffer.disription = values[r, 3].ToString();
                datas.Add(buffer);
            }

            foreach (var item in datas)
            {
                Console.WriteLine($"{item.name} {item.path} {item.disription}");
            }

        }
        
        //[System.Serializable]
        struct SerialData
        {
            public string name;
            public string path;
            public string disription;
        }
    }
}
