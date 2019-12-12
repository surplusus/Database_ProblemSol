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
    class ExcelReader1
    {
        static void Main(string[] args)
        {
            Application application = new Application();
            // 새로 만들기
            //Workbook workbook = application.Workbooks.Add();
            string savePath = System.IO.Directory.GetCurrentDirectory();
            Workbook workbook = application.Workbooks.Open(Filename: savePath + "\\aa.xlsx");
            Worksheet worksheet1 = workbook.Worksheets.Item["Sheet1"];
            //Worksheet worksheet2 = workbook.Worksheets.Item[workbook.Worksheets.Count - 1]; // 마지막 시트
            
            {    // <<<<dynamic을 그대로 사용 가능(마치var처럼)
                //for (int r = 0; r < 3; r++)
                //{
                //    for (int c = 0; c < 3; c++)
                //    {
                //        Range range = worksheet1.Cells[r + 1, c + 1];
                //        var dynamic = range.Value;
                //        Console.WriteLine($"{dynamic}");
                //        //data[r, c] = range.Value;
                //    }
                //}
            }

            Range range1 = worksheet1.Range["A2:C4"];
            object[,] data1 = range1.Value;
            workbook.Close();

            for (int r = 1; r <= data1.GetLength(0); ++r)
            {
                for (int c = 1; c<= data1.GetLength(1); ++c)
                {
                    Console.Write($"{data1[r, c].ToString()} ");
                }
                Console.WriteLine();
            }

            // <<<<<< 직렬화
            SerialData[] serialDatas = new SerialData[3];

            for (int i = 0; i < 3; i++)
            {
                serialDatas[i].Name = data1[i + 1, 1].ToString();
                serialDatas[i].Cost = data1[i + 1, 2].ToString();
                serialDatas[i].Option = data1[i + 1, 3].ToString();
                Console.WriteLine($"{serialDatas[i].Name} {serialDatas[i].Cost} {serialDatas[i].Option}");
            }

            Stream writestream = new FileStream("a.dat", FileMode.Create);
            BinaryFormatter serializer = new BinaryFormatter();
            serializer.Serialize(writestream, serialDatas);
            writestream.Close();

            Stream readstream = new FileStream("a.dat", FileMode.Open);
            BinaryFormatter deserializer = new BinaryFormatter();
            SerialData[] serialDatas1;
            serialDatas1 = (SerialData[])deserializer.Deserialize(readstream);
            readstream.Close();

            Console.WriteLine("*****직렬화된 파일 불러오기*****");
            //Console.WriteLine($"{serialDatas1.Name}");
            foreach (var item in serialDatas1)
            {
                Console.WriteLine($"{item.Name} {item.Cost} {item.Option}");
            }
        }
        
        [Serializable]
        struct SerialData
        {
            public string Name;
            public string Cost;
            public string Option;
        }

    }
    
}