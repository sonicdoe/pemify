# pemify

> Convert certificates to PEM format using OpenSSL.

Currently only supports conversion from DER to PEM.

## Installation

```sh
$ npm install pemify --save
```

## Usage

```js
const fs = require('fs')
const pemify = require('pemify')
const derCertificate = fs.readFileSync('www.example.org.crt')

pemify.der(derCertificate)
// => -----BEGIN CERTIFICATE-----\nMIIF8 …
```

## License

pemify is licensed under the ISC license. See [`LICENSE`](./LICENSE)
for the full license.
