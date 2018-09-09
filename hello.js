const mds = require('./build/Release/addon.node')

const inputarray = [  [-0.4542076, -2.3472019],   [-2.4140841, 5.5251045],
                      [2.427959, -0.5439033],   [-1.0251289, 2.0221781],
                    [-3.6896598, 0.8497193]  ]
const outputarray= mds.solve(inputarray, 2)
console.log(outputarray)

const fs = require('fs')

fs.readFile('winedata.csv', (err, data) => {
    const table = []
    if (err) {
        console.log(err.stack)
        return
    }

    ConvertToTable(data, (table, cate) => {
        console.log(table[0])
        const count = [0, 0, 0]
        // console.log(cate)
        for (let c of cate) {
          count[c - 1]++
        }
        console.log(count)
    })
})
console.log("程序执行完毕")

function ConvertToTable(data, callBack) {
  data = data.toString()
  const table = []
  const cate = []
  let rows = data.split("\n")
  for (let r of rows) {
    let entry = r.split(",")
    cate.push(parseInt(entry.shift()))
    table.push(entry.map(e => parseFloat(e)))
  }
  callBack(table, cate)
}

