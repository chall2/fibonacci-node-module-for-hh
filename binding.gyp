{
  "targets": [
    {  
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "target_name": "test",
      "sources": [ "test.cc" ] 
    }
  ]
}