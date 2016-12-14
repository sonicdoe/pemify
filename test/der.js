import test from 'ava'
import fs from 'fs'
import path from 'path'

import pemify from '..'

const pemPath = path.join(__dirname, 'www.example.org.pem')
const derPath = path.join(__dirname, 'www.example.org.crt')

const pemFile = fs.readFileSync(pemPath, 'utf8').trim()
const derFile = fs.readFileSync(derPath)

test('converts DER to PEM', t => {
  const pem = pemify.der(derFile)
  t.is(pem.trim(), pemFile)
})

test('throws an error if conversion fails', t => {
  t.throws(() => {
    pemify.der(Buffer.alloc(5))
  })
})

test('throws a TypeError if argument is not a buffer', t => {
  t.throws(() => {
    pemify.der({})
  }, TypeError)
})
