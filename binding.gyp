{
  'targets': [
    {
      'target_name': 'pemify',
      'sources': [
        'src/der.cpp'
      ],
      'include_dirs': [
        "<!(node -e \"require('nan')\")",
        "<(node_root_dir)/deps/openssl/openssl/include"
      ]
    }
  ]
}
