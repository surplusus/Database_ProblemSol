using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ExcelDataReader;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Csharp_Implement
{
    class ExcelREader_ExcelDataReader
    {
        public static void Main()
        {
            string filePath = System.IO.Directory.GetCurrentDirectory();
            //Stream stream = File.Open(filePath + "\\aa.xlsx", FileMode.Open,FileAccess.Read);
            Stream stream = new FileStream("aa.xlsx", FileMode.Open);

            List<string>[] list = new List<string>[4];
            using (var reader=ExcelReaderFactory.CreateReader(stream))
            {
                var data = reader.AsDataSet();
                var rowSize = data.Tables[0].Rows.Count;
                var colSize = data.Tables[0].Columns.Count;

                for (int r = 0; r < rowSize; r++)
                {
                    list[r] = new List<string>();
                    for (int c = 0; c < colSize; c++)
                    {
                        var a = data.Tables[0].Rows;
                        string str = data.Tables[0].Rows[r][c].ToString();
                        list[r].Add(str);
                        Console.Write($"{str} ");
                    }
                    Console.WriteLine();
                }
            }
            stream.Close();

            // <<<<<< 직렬화
            SerialData[] serialDatas = new SerialData[3];

            for (int i = 0; i < 3; i++)
            {
                serialDatas[i].Name = list[i+1][0];
                serialDatas[i].Cost = int.Parse(list[i+1][1]);
                serialDatas[i].Option = list[i+1][2];
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
            public int Cost;
            public string Option;
        }
    }
}
