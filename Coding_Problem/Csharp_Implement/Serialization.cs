using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;

namespace Csharp_Implement
{
    [Serializable]
    class NameCard
    {
        public string Name;
        public int Age;
        [NonSerialized]
        public string Phone;
    }

}
