pipeline {
  agent {
    dockerfile true
  }

 stages{
  stage("parallel execution"){
   parallel{
    stage("doxygen"){
     steps{
      sh 'doxygen'
     }
    }

    stage("validation"){
     steps{
      sh 'tools/validate/includeGuard.sh'
     }
    }
    stage("build and test"){
     stages{
      stage("prepare"){
       steps{
        sh '''
         mkdir -p build
         cd build
         cmake .. -G Ninja
        '''
       }
      }

      stage("build"){
       steps{
        sh '''
         cd build
         ninja
        '''
       }
      }

      stage("test"){
       steps{
        sh '''
         cd build
         ctest --output_on_failure
        '''
       }
      }
     }
    }
   }
  }

  stage("upload artifact"){
   steps{
    archiveArtifacts allowEmptyArchive: true, artifacts: 'help/**/*.*', onlyIfSuccessful: true
   }
  }

 }
}
