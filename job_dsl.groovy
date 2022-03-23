folder('Tool') {
    description("Folder for miscellaneous tools.")
}

job('Tool/clone-repository') {
    parameters{
        stringParam('GIT_REPOSITORY_URL', null, 'Git URL of the repository to clone')
    }
    wrappers {
        preBuildCleanup { // Clean before build
            includePattern('**/target/**')
            deleteDirectories()
            cleanupParameter('CLEANUP')
        }
    }
    steps {
        shell('git clone $GIT_REPOSITORY_URL')
    }
}
