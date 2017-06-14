class EventsController < ApplicationController
  before_action :find_event, only: [:show, :edit, :update, :destroy]
  before_action :authenticate_user!, only: [:new, :create, :update, :edit, :destroy]

  def index
    @events = Event.all.order("DATEOF")
  end
  

  def show

  end

  def new
    @event = Event.new
  end

  def create
    @event = Event.new event_params
    @event.dateof = Date.parse(params[:dateof])
    if @event.save
      flash[:success] = "You succesfully created an event"
      redirect_to @event
    else
      flash[:danger] = "Your event did not save successfully"
      render 'new'
    end
  end


  def edit

  end

  def update
    if @event.update event_params
      flash[:success] = "Successfully updated your event"
      redirect_to @event
    else
      flash[:danger] = "Your event was not successfully updated "
      render 'edit'
    end
  end

  def destroy
    @event.destroy
    redirect_to events_path

  end


  private

  def event_params
    params.require(:event).permit(:title, :description, :dateof)
  end

  def find_event
    @event = Event.find(params[:id])
  end

end
