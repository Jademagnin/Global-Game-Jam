type Video = {
    type: 'video'
    name: string
}

type Audio = {
    type: 'audio'
    name: string
}

type Image = {
    type: 'image',
    name: string,
}

type Document = {
    type: 'document'
    name: string
}

type Folder = {
    type: 'folder'
    name: string
    files: Files[]
}

type Files = Folder | Document | Video | Audio | Image

export type Schema = {
    desktop: Files[]
}