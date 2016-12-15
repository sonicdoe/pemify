'use strict'

const addon = require('bindung')('pemify')

module.exports = (der) => {
  if (!Buffer.isBuffer(der)) {
    throw new TypeError('Argument to pemify.der() must be a buffer')
  }

  return addon.der(der)
}
