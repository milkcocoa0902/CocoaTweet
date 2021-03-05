def unittestBadge = addEmbeddableBadgeConfiguration(id: "unittest", subject: "unit test")

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
         cmake .. -G Ninja -DENABLE_TEST=TRUE
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
        script{
         unittestBadge.setStatus('running')
         try{
          sh '''
           cd build
           ctest --output-on-failure
          '''
          unittestBadge.setStatus('passing')
         }catch(Exception error){
          unittestBadge.setStatus('failed')
          error 'unittest failed'
         }
        }
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
